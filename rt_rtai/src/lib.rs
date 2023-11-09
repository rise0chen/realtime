mod ffi;

use core::sync::atomic::{AtomicU64, Ordering};
use core::time::Duration;
use libc::{c_int, c_longlong, c_void};
use nix::unistd::Uid;
use realtime_core::*;

static ID: AtomicU64 = AtomicU64::new(1);

pub struct Rtai {
    task: *mut c_void,
    task_id: u64,
    start_time: c_longlong,
}
impl Rtai {
    pub fn new(prio: i32) -> Result<Self> {
        // 要求 root 权限，否则无法启动
        if !Uid::effective().is_root() {
            return Err(ErrorKind::NotRoot);
        }
        let task_id = ID.fetch_add(1, Ordering::Relaxed);
        let sched = unsafe { ffi::ffi_SCHED_FIFO() };
        let task = unsafe { ffi::ffi_rt_task_init_schmod(task_id, prio, 0, 0, sched, 0b11) };

        Ok(Rtai {
            task,
            task_id,
            start_time: 0,
        })
    }
    pub fn get_time_ns() -> u64 {
        unsafe { ffi::ffi_rt_get_time_ns() as u64 }
    }
}
impl RealTime for Rtai {
    fn start(&mut self, period: Duration) -> Result<()> {
        unsafe {
            self.start_time = ffi::ffi_rt_get_time();
            let period = ffi::ffi_nano2count(period.as_nanos() as c_longlong);
            log::info!(
                "rtai start: period={}, start_time={}",
                period,
                self.start_time
            );
            ffi::ffi_rt_set_periodic_mode();
            ffi::ffi_start_rt_timer(period as c_int);
            ffi::ffi_rt_make_hard_real_time();
            match ffi::ffi_rt_task_make_periodic(self.task, self.start_time, period) {
                0 => Ok(()),
                x => Err(ErrorKind::Unknown(x as isize)),
            }
        }
    }
    fn stop(&mut self) -> Result<()> {
        if self.start_time == 0 {
            return Ok(());
        }
        unsafe {
            ffi::ffi_rt_make_soft_real_time();
            ffi::ffi_stop_rt_timer();
        }
        self.start_time = 0;
        Ok(())
    }

    fn wait_period(&mut self) -> Result<()> {
        if self.start_time == 0 {
            return Err(ErrorKind::NotStart);
        }
        match unsafe { ffi::ffi_rt_task_wait_period() } {
            0 => Ok(()),
            x => Err(ErrorKind::Unknown(x as isize)),
        }
    }
}

impl Drop for Rtai {
    fn drop(&mut self) {
        let _ = self.stop();
        unsafe { ffi::ffi_rt_task_delete(self.task) };
        log::info!("task:{} dropped", self.task_id);
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn tolerance() {
        let mut rtai = Rtai::new(90).unwrap();
        rtai.start(Duration::from_millis(1)).unwrap();
        rtai.wait_period().unwrap();
        let mut last_time = clock_source::now();
        for _ in 0..1_000 {
            rtai.wait_period().unwrap();
            let now = clock_source::now();
            if now - last_time > 1_100_000 {
                println!("{}", now - last_time - 1_000_000);
            }
            assert!(now - last_time < 1_100_000);
            last_time = now;
        }
    }
}

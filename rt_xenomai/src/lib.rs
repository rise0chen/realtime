mod ffi;

use core::time::Duration;
use libc::{c_longlong, c_ulong};
use nix::unistd::Uid;
use realtime_core::*;

pub struct Xenomai {
    start_time: c_longlong,
}

impl Xenomai {
    pub fn new(prio: i32) -> Result<Self> {
        // 要求 root 权限，否则无法启动
        if !Uid::effective().is_root() {
            return Err(ErrorKind::NotRoot);
        }
        unsafe { ffi::init() };
        match unsafe { ffi::shadow(prio, 1) } {
            0 => {}
            x => return Err(ErrorKind::Unknown(x as isize)),
        }

        core_affinity::set_for_current(core_affinity::CoreId { id: 0 });
        Ok(Self { start_time: 0 })
    }

    pub fn get_time_ns() -> u64 {
        unsafe { ffi::read() as u64 }
    }
}
impl RealTime for Xenomai {
    fn start(&mut self, period: Duration) -> Result<()> {
        let period = period.as_nanos() as c_longlong;
        let start_time = unsafe { ffi::read() } + period;
        match unsafe { ffi::set_periodic(start_time, period) } {
            0 => {
                self.start_time = start_time;
                log::info!(
                    "Xenomai start: period={}, start_time={}",
                    period,
                    start_time
                );
                Ok(())
            }
            x => Err(ErrorKind::Unknown(x as isize)),
        }
    }
    fn stop(&mut self) -> Result<()> {
        if self.start_time == 0 {
            return Ok(());
        }
        match unsafe { ffi::set_periodic(0, 0) } {
            0 => {
                self.start_time = 0;
                Ok(())
            }
            x => Err(ErrorKind::Unknown(x as isize)),
        }
    }
    fn wait_period(&mut self) -> Result<()> {
        if self.start_time == 0 {
            return Err(ErrorKind::NotStart);
        }
        let mut overrun: c_ulong = 0;
        match unsafe { ffi::wait_period(&mut overrun as *mut _) } {
            0 => Ok(()),
            x => Err(ErrorKind::Unknown(x as isize)),
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn tolerance() {
        let mut xenomai = Xenomai::new(90).unwrap();
        xenomai.start(Duration::from_millis(1)).unwrap();
        xenomai.wait_period().unwrap();
        let mut last_time = clock_source::now();
        for _ in 0..1_000 {
            xenomai.wait_period().unwrap();
            let now = clock_source::now();
            if now - last_time > 1_200_000 {
                println!("{}", now - last_time - 1_000_000);
            }
            assert!(now - last_time < 1_200_000);
            last_time = now;
        }
    }
}

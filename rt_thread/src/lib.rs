use realtime_core::*;
use std::thread;
use std::time::{Duration, Instant};
use thread_priority::*;

pub struct RtThread {
    last_time: Instant,
    period: Duration,
}
impl RtThread {
    pub fn new(prio: u8) -> Result<Self> {
        if prio > 0 {
            let thread_id = thread_native_id();
            #[cfg(not(windows))]
            let policy = ThreadSchedulePolicy::Realtime(RealtimeThreadSchedulePolicy::Fifo);
            let rt = if prio > 99 { 99 } else { prio };
            let priority = ThreadPriority::Crossplatform(rt.try_into().unwrap());
            #[cfg(not(windows))]
            if !nix::unistd::Uid::effective().is_root() {
                return Err(ErrorKind::NotRoot);
            }
            #[cfg(not(windows))]
            let result = set_thread_priority_and_policy(thread_id, priority, policy);
            #[cfg(windows)]
            let result = set_thread_priority(thread_id, priority);
            if let Err(err) = result {
                log::warn!("failed to set_thread_priority: {:?}", err);
            }
        }

        Ok(Self {
            last_time: Instant::now(),
            period: Duration::ZERO,
        })
    }
}
impl RealTime for RtThread {
    fn start(&mut self, period: Duration) -> Result<()> {
        self.last_time = Instant::now();
        self.period = period;
        Ok(())
    }
    fn stop(&mut self) -> Result<()> {
        self.period = Duration::ZERO;
        Ok(())
    }
    fn wait_period(&mut self) -> Result<()> {
        if self.period == Duration::ZERO {
            return Err(ErrorKind::NotStart);
        };
        let next_time = self.last_time + self.period;
        let now = Instant::now();
        if now < next_time {
            let sleep = next_time - now;
            thread::sleep(sleep);
        }
        self.last_time = next_time;
        Ok(())
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn tolerance() {
        let mut rtai = RtThread::new(90).unwrap();
        rtai.start(Duration::from_millis(1)).unwrap();
        rtai.wait_period().unwrap();
        let mut last_time = clock_source::now();
        for _ in 0..1_000 {
            rtai.wait_period().unwrap();
            let now = clock_source::now();
            if now - last_time > 1_600_000 {
                println!("{}", now - last_time - 1_000_000);
            }
            assert!(now - last_time < 1_600_000);
            last_time = now;
        }
    }
}

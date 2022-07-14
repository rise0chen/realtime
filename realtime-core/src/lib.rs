use core::time::Duration;

#[derive(Debug)]
pub enum ErrorKind {
    NotRoot,
    NotStart,
    Unknown(isize),
}
pub type Result<T> = core::result::Result<T, ErrorKind>;

pub trait RealTime {
    /// Start a periodic real-time task.
    fn start(&mut self, period: Duration) -> Result<()>;
    /// Stop a periodic real-time task.
    fn stop(&mut self) -> Result<()>;
    /// Delay the current task until the next periodic release point is reached.
    fn wait_period(&mut self) -> Result<()>;
}

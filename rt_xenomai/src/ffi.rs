use libc::{c_int, c_longlong, c_ulong};

#[link(name = "xenomai")]
extern "C" {
    pub fn init();
    pub fn shadow(prio: c_int, mode: c_int) -> c_int;
    pub fn set_periodic(start_time: c_longlong, period: c_longlong) -> c_int;
    pub fn wait_period(overruns_r: *mut c_ulong) -> c_int;
    pub fn read() -> c_longlong;
}

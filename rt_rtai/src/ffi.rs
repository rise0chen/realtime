use libc::{c_int, c_longlong, c_ulong, c_void};

#[link(name = "rtai")]
extern "C" {
    pub fn ffi_rt_task_init_schmod(
        name: c_ulong,
        priority: c_int,
        stack_size: c_int,
        max_msg_size: c_int,
        policy: c_int,
        cpus_allowed: c_int,
    ) -> *mut c_void;
    pub fn ffi_rt_task_delete(task: *mut c_void);
    pub fn ffi_nano2count(nanos: c_longlong) -> c_longlong;
    pub fn ffi_rt_set_periodic_mode();
    pub fn ffi_start_rt_timer(period: c_int) -> c_longlong;
    pub fn ffi_stop_rt_timer();
    pub fn ffi_rt_make_hard_real_time();
    pub fn ffi_rt_task_make_periodic(
        task: *mut c_void,
        start_time: c_longlong,
        period: c_longlong,
    ) -> c_int;
    pub fn ffi_rt_make_soft_real_time();
    pub fn ffi_rt_task_wait_period() -> c_int;
    pub fn ffi_rt_get_time() -> c_longlong;
    pub fn ffi_rt_get_time_ns() -> c_longlong;
    pub fn ffi_SCHED_FIFO() -> c_int;
    pub fn ffi_SCHED_RR() -> c_int;
}

#include "rtai_lxrt.h"

int ffi_SCHED_FIFO() {
    return SCHED_FIFO;
}
int ffi_SCHED_RR() {
    return SCHED_RR;
}

unsigned long ffi_nam2num(const char* name) {
    return nam2num(name);
}

RT_TASK* ffi_rt_task_init_schmod(unsigned long name, int priority, int stack_size, int max_msg_size, int policy, int cpus_allowed) {
    return rt_task_init_schmod(name, priority, stack_size, max_msg_size, policy, cpus_allowed);
}

int ffi_rt_task_delete(RT_TASK *task) {
    return rt_task_delete(task);
}

RTIME ffi_nano2count(RTIME nanos) {
    return nano2count(nanos);
}

void ffi_rt_set_periodic_mode() {
    rt_set_periodic_mode();
}

RTIME ffi_start_rt_timer(int period) {
    return start_rt_timer(period);
}

void ffi_stop_rt_timer() {
    stop_rt_timer();
}

void ffi_rt_make_hard_real_time() {
    rt_make_hard_real_time();
}

int ffi_rt_task_make_periodic(RT_TASK *task, RTIME start_time, RTIME period) {
    return rt_task_make_periodic(task, start_time, period);
}

int ffi_rt_task_wait_period() {
    return rt_task_wait_period();
}

RTIME ffi_rt_get_time_ns() {
    return rt_get_time_ns();
}

RTIME ffi_rt_get_time() {
    return rt_get_time();
}

void ffi_rt_make_soft_real_time() {
    rt_make_soft_real_time();
}

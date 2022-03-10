#include <trank/native/task.h>
#include <trank/native/timer.h>
#include <xenomai/init.h>

void init(void) {
  int argc = 0;
  char *const argv[] = {"", ""};
  xenomai_init(&argc, &argv);
}

int shadow(int prio, int mode) {
  return rt_task_shadow(NULL, NULL, prio, mode);
}

int set_periodic(RTIME start_time, RTIME period) {
  return rt_task_set_periodic(NULL, start_time, period);
}

int wait_period(unsigned long *overruns_r) {
  return rt_task_wait_period(overruns_r);
}

RTIME read(void) { return rt_timer_read(); }

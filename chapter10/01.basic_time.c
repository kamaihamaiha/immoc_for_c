/**
 * 时间的基本概念
 */
#include "io_utils_teacher.h"
#include <time.h>
#include <sys/timeb.h>
int main(){

  // time_t: 从 1970年 开始

  // clock_t: 进程所消耗的运行时间
  // struct tm: 人类可读的时间
  // struct timespec: C11 开始，有纳秒。优先使用这个😀
  // struct timeb: 包含 time_t, 毫秒, 时区,
  // struct timeval: Unix 有(Ubuntu struct_timeval.h), 秒, 微秒

  struct tm;
  struct timespec;
  struct timeb;
  struct timeval;
  return 0;
}
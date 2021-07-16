/**
 * 获取系统时间.
 * 用宏写一个跨平台的函数，在 time_utils.h 里面
 */
#include "io_utils_teacher.h"
#include "time_utils.h"
#include <time.h>
int main() {

  time_t current_time;

  //获取系统时间
  time(&current_time);
  PRINT_LONG(current_time);

  //或者这样
  current_time = time(NULL);
  PRINT_LONG(current_time);

  PRINT_LLONG(TimeInMillisecond());

  return 0;
}


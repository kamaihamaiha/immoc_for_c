/**
 * 计算时间差
 * difftime() 单位是秒，不够精确。所以下面用了毫秒。
 * time() 返回系统时间，更符合描述真实世界时间的变化
 * clock() 处理器耗时，是处理器对时间单位. 更能真实反应程序运行耗时
 */

#include "io_utils_teacher.h"
#include "time_utils.h"
#include <time.h>
#include <string.h>
#include <stdio.h>

#define PI 3.1415926

void DoHardWork() {
  double sum = 0;
  for (int i = 0; i < 10000000; ++i) {
    sum += i * i / PI;
  }
  PRINT_DOUBLE(sum);
}

int main() {

  time_t time_start = time(NULL);
  DoHardWork();
  time_t time_end = time(NULL);
  double diff_time = difftime(time_start,time_end);
  PRINT_DOUBLE(diff_time);


  //通过毫秒计算时间差
  long long time_milli_start = TimeInMillisecond();
  DoHardWork();
  long long time_milli_end = TimeInMillisecond();

  PRINT_LLONG(time_milli_end - time_milli_start);


  //通过 CPU 时间单位，计算时间差。要用到宏：CLOCKS_PER_SEC
  clock_t time_start_c = clock();
  DoHardWork();
  clock_t time_end_c = clock();

  double diff_time_c = (time_end_c - time_start_c) * 1.0 / CLOCKS_PER_SEC;
  PRINT_DOUBLE(diff_time_c);

  return 0;
}

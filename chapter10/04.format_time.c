/**
 * 格式化时间
 * // Wed Mar 17 21:07:27 2021
 * asctime()、ctime(). 使用共享内存，多并发会引起问题
 *
 * //自定义格式："%Y-%m-%d %H:%M:%S"，"%F %T" 这两个是等价的
 * strftime()
 */
#include "io_utils_teacher.h"
#include "time_utils.h"
#include <time.h>
#include <stdio.h>
int main() {

  time_t cur_time;
  time(&cur_time);

  struct tm *calendar_time = localtime(&cur_time);

  //
  char *format_time = asctime(calendar_time);
  puts(format_time);
  puts(ctime(&cur_time));

  char cur_time_s[20];
  const char *custom_fmt = "%Y-%m-%d %H:%M:%S";
  const char *custom_fmt2 = "%F %T";
  const char *custom_fmt3 = "%Y%m%d%H%M%S";
  strftime(cur_time_s,20,custom_fmt2,calendar_time);

  puts(cur_time_s);

  //得到毫秒
  int time_mill = TimeInMillisecond() % 1000;
  size_t size = strftime(cur_time_s,20,custom_fmt3,calendar_time);
  PRINT_INT(size);
  sprintf(cur_time_s + 14,"%03d",time_mill);
  puts(cur_time_s);
  return 0;
}

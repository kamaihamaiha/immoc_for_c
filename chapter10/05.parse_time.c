/**
 * 解析时间
 * strftime() POSIX 对 C 标准库对扩展
 * sscanf() 从字符串开始扫描
 */
#define _XOPEN_SOURCE
#include <stdio.h>
#include "io_utils_teacher.h"
#include "time_utils.h"
#include <time.h>

int main() {

  time_t cur_time_2;
  time(&cur_time_2);

  struct tm *calender_time_2 = localtime(&cur_time_2);

  size_t time_size = 20;
  char time_s_2[time_size];
  char *time_fmt = "%F %T";

  strftime(time_s_2, time_size, time_fmt, calender_time_2);

  puts(time_s_2);

  char *time_s_1 = "2020-01-01 12:22:12.436";
  struct tm calender_time_1;
  char *time_unparse_part = strptime(time_s_1, time_fmt, &calender_time_1);

  PRINT_INT(calender_time_1.tm_year);
  PRINT_INT(calender_time_1.tm_mon);
  PRINT_INT(calender_time_1.tm_mday);
  PRINT_INT(calender_time_1.tm_hour);
  PRINT_INT(calender_time_1.tm_min);
  PRINT_INT(calender_time_1.tm_sec);

  puts(time_unparse_part);

  //解析毫秒
  int millisecond;
  sscanf(time_unparse_part,".%3d",&millisecond);
  PRINT_INT(millisecond);
  return 0;
}
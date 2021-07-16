//
// Created by 张开旭 on 2021/3/17.
//
#include "io_utils_teacher.h"
#include "time_utils.h"
#include "time.h"

int main(){
  time_t current_time;
  time(&current_time);

  //localtime: 本地时间，有时区. 时间戳 -> tm
  struct tm *calendar_time = localtime(&current_time);
  PRINT_INT(calendar_time->tm_year);
  PRINT_INT(calendar_time->tm_mon);
  PRINT_INT(calendar_time->tm_mday);
  PRINT_INT(calendar_time->tm_hour);
  PRINT_INT(calendar_time->tm_min);
  PRINT_INT(calendar_time->tm_sec);

  //tm -> 时间戳
  PRINT_LONG(current_time);

  calendar_time->tm_sec = 90;

  PRINT_INT(calendar_time->tm_min);
  PRINT_INT(calendar_time->tm_sec);
  time_t current_time2 = mktime(calendar_time);
  PRINT_LONG(current_time2);

  time_t gm_time;
  time(&gm_time);
  //得到格林威治时间
  struct tm *gm_cur_time = gmtime(&gm_time);
  PRINT_INT(gm_cur_time->tm_year);
  PRINT_INT(gm_cur_time->tm_mon);
  PRINT_INT(gm_cur_time->tm_mday);
  PRINT_INT(gm_cur_time->tm_hour);
  PRINT_INT(gm_cur_time->tm_min);
  PRINT_INT(gm_cur_time->tm_sec);

  return 0;
}

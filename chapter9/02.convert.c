/**
 * 库：<stdlib.h>
 * 函数：使用简单，适用于简单、要求不高的场景
 * atof(),atoi(),atol(),atoll()
 *
 * a: ascii
 * atof: string -> floating-point number
 * atoi: string -> integer
 * atol: string -> long integer
 * atoll: string -> long long integer
 *
 * 函数：可重复解析，更安全，功能更强大
 * strtol, strtoll: 将字符串转换为有符号整型
 * strtoul, strtoull: 将字符串转换为无符号整型
 * strtof, strtod, strtold: 将字符串转换为浮点型
 * stroimax, strtoumax
 */

#include "io_utils_teacher.h"
#include <stdlib.h>
#include <errno.h>

int main() {

  PRINT_DOUBLE(atof("12.34"));
  PRINT_INT(atoi("1234"));
  PRINT_INT(atol("1234"));
  PRINT_INT(atoll("1234"));

  char const *const kInput = "1 200000000000 349";
  char const *start = kInput;
  char *end;
  while (1){
    errno = 0;
    const long i = strtol(start,&end,10);

    if (start == end){ //转换完成
      break;
    }

    printf("'%.*s'\t ==> %ld.",(int)(end - start),start,i);
    if (errno == ERANGE){
      perror("");
    }

    putchar('\n');
    start = end;
  }

  PRINTLNF("Left: %s",end);
  return 0;
}
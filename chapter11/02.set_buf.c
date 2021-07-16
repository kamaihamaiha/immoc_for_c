/**
 * 文件流的缓冲
 *
 * 设置缓冲：
 * setbuf(不建议用了)、BUFSIZ（宏）、setvbuf()
 *
 * 宏：
 * _IOFBF : 全部缓冲
 * _IOLBF : 按行缓冲
 * _IONBF : 不缓冲
 *
 * 缓冲区生命周期（作用域）要超过文件的生命周期，千万不要小于文件生命周期. 获取主动申请缓冲内存，用 malloc
 *
 * 主动清空缓冲区：
 * fflush()
 */
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include "io_utils_teacher.h"

int main() {

  FILE *file = fopen("../CMakeLists.txt", "r");

  char buf[8192];

  if (file) {
    setvbuf(file, buf, _IOLBF, 8192);

    // ...
    printf("Open file success!\n");

    // 得到文件错误码
    int err = ferror(file);

    // 文件是否到了结尾
    int eof = feof(file);

    PRINT_INT(err);
    PRINT_INT(eof);

    //主动清空缓冲区
    fflush(file);

    fclose(file);
  } else {
    PRINT_INT(errno);
    strerror(errno);
    perror("fopen");
  }

  return 0;
}
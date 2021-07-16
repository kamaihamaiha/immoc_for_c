/**
 * 输入输出流
 *
 * errno: 错误码
 * stdout: 标准输出流
 * stderr: 标准错误流
 * stdin:  标准输入流
 */
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include "io_utils_teacher.h"

int main(){

  FILE *file = fopen("../CMakeLists.txt","r");
  if (file){
    // ...
    printf("Open file success!\n");

    // 得到文件错误码
    int err = ferror(file);

    // 文件是否到了结尾
    int eof = feof(file);

    PRINT_INT(err);
    PRINT_INT(eof);

    fclose(file);
  } else {
    PRINT_INT(errno);
    strerror(errno);
    perror("fopen");
  }


  // 查看错误码
  for (int i = 0; i < 10; ++i) {
    PRINT_INT(i);
    puts(strerror(i));
  }

  return 0;
}

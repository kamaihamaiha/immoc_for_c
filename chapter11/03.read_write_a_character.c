/**
 * 读写一个字符
 * getchar(stdin) 从 stdin 中读一个字符
 * getc(FILE *stream)、fgetc(FILE *stream)  从指定的流中读取一个字符
 *
 * 宏：
 * EOF 标记文件流结束，是整型。
 *
 * 写一个字符
 * int putchar(int ch) 向控制台(stout) 写入一个字符
 * putc(int ch, FILE *stream)、fputc(int ch, FILE *stream) 向参数指定的流中写入字符
 *
 */
#include <stdio.h>
#include <errno.h>
#include "io_utils_teacher.h"

void ReadFile(const char *file_path) {

  FILE *file = fopen(file_path, "r");
  if (file) {
    int next_char;
    while ((next_char = getc(file)) != EOF) {
      putchar(next_char);
    }
  } else {
    PRINT_INT(errno);
  }

  //清空缓冲，然后关闭文件
  fflush(file);
  fclose(file);
}

int main() {

  /*int input;
  while ((input = getchar()) != EOF) {
    if (input == '\n') continue; //不输出换行
//    printf("%c", input);
    putchar(input);
  }
  printf("\n");*/

  const char *file_path = "../CMakeLists.txt";
  ReadFile(file_path);

  return 0;
}

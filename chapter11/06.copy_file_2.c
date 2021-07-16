//
// Created by 张开旭 on 2021/3/22.
//

#include "io_utils_teacher.h"
#include "time_utils.h"
#include <stdio.h>

//定义各种异常的宏

#define COPY_SUCCESS 0
#define COPY_ILLEGAL_ARGUMENTS -1
#define COPY_SRC_OPEN_ERROR -2
#define COPY_SRC_READ_ERROR -3
#define COPY_DEST_OPEN_ERROR -4
#define COPY_DEST_WRITE_ERROR -5
#define COPY_UNKNOWN_ERROR -100

#define BUFFER_SIZE 1024

/**
 * 复制文件
 * @param src 被复制的文件
 * @param dest 新的文件副本
 * @return 成功返回 0，失败返回自定义的错误码
 */
int CopyFile(const char *src, char const *dest) {
  if (!src || !dest) {
    return COPY_ILLEGAL_ARGUMENTS;
  }

  FILE *src_file = fopen(src, "r");
  if (!src_file) { //打开被复制的文件失败
    return COPY_SRC_OPEN_ERROR;
  }

  FILE *dest_file = fopen(dest, "w");
  if (!dest_file) { //打开目标文件失败
    fclose(src_file); //并且要关闭 src file
    return COPY_DEST_OPEN_ERROR;
  }

  int result;

  while (1) {
    int next = fgetc(src_file);
    if (next == EOF) { // 以下细分了三种情况
      if (ferror(src_file)) {
        result = COPY_SRC_READ_ERROR;
      } else if (feof(src_file)) {
        result = COPY_SUCCESS;
      } else {
        result = COPY_UNKNOWN_ERROR;
      }
      break;
    }

    // 往 dest_file 文件写入数据
    if (fputc(next, dest_file) == EOF) {
      result = COPY_DEST_WRITE_ERROR;
      break;
    }
  }

  //关闭文件
  fclose(src_file);
  fclose(dest_file);

  return result;

}

/**
 * 复制文件
 * @param src 被复制的文件
 * @param dest 新的文件副本
 * @return 成功返回 0，失败返回自定义的错误码
 */
int CopyFile2(const char *src, char const *dest) {
  if (!src || !dest) {
    return COPY_ILLEGAL_ARGUMENTS;
  }

  FILE *src_file = fopen(src, "r");
  if (!src_file) { //打开被复制的文件失败
    return COPY_SRC_OPEN_ERROR;
  }

  FILE *dest_file = fopen(dest, "w");
  if (!dest_file) { //打开目标文件失败
    fclose(src_file); //并且要关闭 src file
    return COPY_DEST_OPEN_ERROR;
  }

  int result;
  char buffer[BUFFER_SIZE];
  char *next;
  while (1) {
    next = fgets(buffer, BUFFER_SIZE, src_file);
    if (!next) { // 以下细分了三种情况
      if (ferror(src_file)) {
        result = COPY_SRC_READ_ERROR;
      } else if (feof(src_file)) {
        result = COPY_SUCCESS;
      } else {
        result = COPY_UNKNOWN_ERROR;
      }
      break;
    }

    // 往 dest_file 文件写入数据
    if (fputs(buffer, dest_file) == EOF) {
      result = COPY_DEST_WRITE_ERROR;
      break;
    }
  }

  //关闭文件
  fclose(src_file);
  fclose(dest_file);

  return result;

}


int main() {

  char *method1 = "CopyFile";
  TimeCost(NULL);
  int ret = CopyFile("chapter11/data/View.java", "chapter11/data_copy/View.java");
  TimeCost(method1);
  PRINT_INT(ret);

  char *method2 = "CopyFile2";
  TimeCost(NULL);
  int ret2 = CopyFile2("chapter11/data/View.java", "chapter11/data_copy/View.java");
  TimeCost(method2);
  PRINT_INT(ret2);

  return 0;
}
//
// Created by 张开旭 on 2021/3/5.
//
#include <stdio.h>
#include "io_utils.h"

#define ARRAY_SIZE 10

int global_arr[ARRAY_SIZE];
int main(void) {

  int arr[ARRAY_SIZE];

  //初始化列表赋值
  int arr2[ARRAY_SIZE] = {9,8,7,6,5,4,3,2,1,0};

  //初始化列表赋值一部分
  double arr_double[5] = {1.2,3.4};

  char arr_char[4] = {[2] = '2'};
  for (int i = 0; i < ARRAY_SIZE; ++i) {
//    arr[i] = i + 1;
    PRINT_INT(arr[i]);
    PRINT_INT(global_arr[i]);
  }

  for (int i = 0; i < 4; ++i) {
    PRINT_CHAR(arr_char[i]);
  }


  return 0;
}
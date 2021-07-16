#include <stdio.h>
#include "io_utils.h"
#define SIZE  8
int main(void) {

  int arr[SIZE];
  arr[0] = 9;

  *(arr + 1) = 90;

  int a_size = 3;
  //C99 开始支持：VLA 变长数组：数组的长度可以用变量声明。GCC支持，MSVC 不支持
  int arry_of_a_size[a_size];

  printf("%p\n", arr);
  printf("%p\n", &arr);
  printf("%d\n", *arr);
  printf("%d\n", *arry_of_a_size);



  return 0;
}
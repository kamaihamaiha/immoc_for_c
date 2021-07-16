//只读指针变量 + 只读变量指针

#include <stdio.h>
#include "io_utils_teacher.h"
int main(void){

  int a = 0;
  int b = 10;

  int * const p1 = &a;
  int const * p2 = &b;

 /* p1 = &b;
  *p2 = a;
  p2 = &b;*/

  return 0;
}
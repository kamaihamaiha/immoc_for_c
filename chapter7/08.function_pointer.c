/**
 * 函数指针
 *
 * 1. int *(f1(int, double));
 * 2. int (*f2)(int, double);
 * 3. int *(*f3)(int, double);
 *
 * typedef: 别名
 */
#include "io_utils_teacher.h"

typedef int Boolean;
typedef int *IntP;
typedef int IntArray[];
typedef int (*Func)(int,int);


int add(int x, int y) {
  return x + y;
}
int main() {

  int num = 3;
  int *p = &num;
  IntP ip = &num;

  IntArray ia = {2,3,4};

  PRINT_HEX(&main);

  //函数指针
  int (*add_fun)(int x, int y) = &add;

  int res = add_fun(3, 4);
  PRINT_INT(res);

  Func func = &add;
  res = func(3,5);
  PRINT_INT(res);
  return 0;
}

/**
 * 指针运算
 */

#include "io_utils_teacher.h"
int main(void){

  int a = 2;
  int *p = &a;

  /*PRINT_INT(p);
  PRINT_INT(*p);
  PRINT_INT(p + 1);
  PRINT_INT(*(p + 1));
  PRINT_INT(sizeof(int));*/

  //数组相当于 const 指针
  int arr[] = {1,2,3,4,5,6,7};
  int *pa = arr;
  PRINT_INT(pa);
  PRINT_INT(arr);

  PRINT_INT(*(pa + 1));
  PRINT_INT(pa[1]);
  PRINT_INT(*(arr + 1));
  PRINT_INT(arr[1]);
  PRINT_INT(*(1 + arr));
  PRINT_INT(1[arr]);


  return 0;
}
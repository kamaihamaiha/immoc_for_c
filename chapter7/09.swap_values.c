#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "io_utils_teacher.h"

//通过宏，来交换两个变量的值. typeof 可以自动识别类型，gcc 有，并不通用。MSVC 没有，但 C++ 有。
#define SWAP(x,y) do {typeof(x) temp = x; x = y; y = temp;} while (0)

/**
 * 交换两个变量的值
 * @param x
 * @param y
 * @param size 变量类型占用的空间大小
 */
void Swap(void* x, void* y,size_t size){
  void *temp = malloc(size);
  if (temp){
    memcpy(temp,x,size);
    memcpy(x,y,size);
    memcpy(y,temp,size);

    free(temp);
  }
}

/**
 * 交换 int 型变量的值
 * @param x
 * @param y
 */
void SwapInt(int *x, int *y){
  int temp = *x;
  *x = *y;
  *y = temp;
}
int main(){

  int ia = 1;
  int ib = 2;

  SWAP(ia,ib);
  PRINT_INT(ia);
  PRINT_INT(ib);


  Swap(&ia,&ib,sizeof(int ));
  PRINT_INT(ia);
  PRINT_INT(ib);

  //通过宏，来交换两个变量的值
  SWAP(ia,ib);
  PRINT_INT(ia);
  PRINT_INT(ib);

  if(ia)SWAP(ia,ib);else {

  }

  //typeof, 自动识别变量类型
  return 0;
}
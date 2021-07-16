/**
 * 1. 不要使用硬编码复制给指针
 * 2. 空指针 NULL 的用法
 * 3. 野指针
 */
#include <stdio.h>
int main(void){
  int *p = NULL;

  printf("%p\n",p);
  printf("%d\n",*p);


  //野指针：指向了一个内存被回收的地址，失效的地址，也就是没有用的指针
  return 0;
}
/**
 * 空参数：main(void)
 * 如果函数没有参数，那么 C语言不知道有多少个参数，你传入多少个都不报错. 但 C++ 就会检查。
 */
#include <stdio.h>
void EmptyParamList(void){
  puts("hello");
}

int Add(int a,int b);

//声明时，参数名也可以不写
int AddNew(int ,int );

int main(void){
  EmptyParamList();
  Add(1,2);
  return 0;
}

int Add(int a,int b){
  return a + b;
}

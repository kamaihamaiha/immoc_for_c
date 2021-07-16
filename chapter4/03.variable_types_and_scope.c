/**
 * 变量作用域：
 * 1. function scope
 * 2. block scope
 * 3. file scope
 * 4. proto scope
 *
 * 变量类型：
 * 1. auto
 * 2. static
 * 3. register //寄存器变量
 */

#include <stdio.h>

//file scope
int global_size = 10;

//本地静态变量
void LocalStaticVariable() {
  //静态变量：作用域全局，数值不会因为函数退出而销毁，int 初始默认值是 0
  static int static_my_value;

  //自动变量：函数作用域/块作用域，随着函数和块退出而销毁，没有默认初始值
  auto int non_static_my_value = 0;

  printf("static_my_value: %d\n",static_my_value++);
  printf("non_static_my_value: %d\n",non_static_my_value++);
}

//清理
void CleanMemory(){
  int eraser = -1;
}

//size: proto scope => 原型作用域
int Look(int size, int arry[size]);

int main(void) {

  //function scope
  auto int age = 10;

  {
    //block scope
    auto int money = 9;
  }

  LocalStaticVariable();
  CleanMemory();
  LocalStaticVariable();
  CleanMemory();
  LocalStaticVariable();
  LocalStaticVariable();

  return 0;
}

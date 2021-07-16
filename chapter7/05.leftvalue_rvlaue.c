//
// Created by 张开旭 on 2021/3/7.
//

int main(void) {


  //左值：是一块内存空间,是被操作的。右值：是一个 value
  int a;
  a = 2;

  int *p = &a;
  *p = 3;

  int b = *p;

  // ERROR &a = p;
  // Error *p + 1 = 3;

  //这三行是等价的
  *p++ = 4;
  *(p++) = 4;
  *p = 4; p++;
  return 0;
}
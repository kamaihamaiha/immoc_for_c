//
// 变长参数
//
#include <stdio.h>
#include <stdarg.h>

void HandlerParams(int arg_count, ...) {
  //1. 获取变长参数
  va_list args;

  //2. 开始遍历
  va_start(args, arg_count);

  for (int i = 0; i < arg_count; ++i) {
    //3. 取出对应参数
    int arg = va_arg(args, int);
    printf("%d : %d\n", i, arg);
  }

  //4. 结束遍历
  va_end(args);
}
int main(void) {
  HandlerParams(5,1,2,3,4,5);
  return 0;
}
/**
 * 字符计数
 *
 * 注意，CLion 直接运行，想结束不太好使。要用 gcc 编译器手动编译，然后想停止按下 Control + D
 */
#include <stdio.h>

int main() {

  long nc = 0;
  /*while (getchar() != EOF) {
    nc++;
    printf("输入字符数量：%ld\n", nc);
  }*/

  for (nc = 0; getchar() != EOF; ++nc)
    ;
  printf("输入字符数量：%ld\n", nc);

  return 0;
}
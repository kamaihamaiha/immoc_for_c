// 行计数

#include <stdio.h>
int main() {

  int line_num = 0;
  int c;
  while ((c = getchar()) != EOF) {
    if (c == '\n') line_num++;
  }

  printf("行数：%d\n",line_num);
  return 0;
}


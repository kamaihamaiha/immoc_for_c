// 统计空格、制表符、换行符
#include <stdio.h>
int main() {

  int space_count = 0;
  int table_count = 0;
  int line_count = 0;

  int c;

  while ((c = getchar()) != EOF) {
    switch (c) {
      case ' ':space_count++;
        break;
      case '\t':table_count++;
        break;
      case '\n':line_count++;
        break;
      default:break;
    }
  }

  printf("空格个数：%d\n", space_count);
  printf("制表符个数：%d\n", table_count);
  printf("换行符个数：%d\n", line_count);
  return 0;
}


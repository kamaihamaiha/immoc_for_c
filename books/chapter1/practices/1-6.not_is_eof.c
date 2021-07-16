// 验证表达式 getchar() != EOF 的值

#include <stdio.h>
int main(){
  int value;

  // 控制台要有输入结果
  value = getchar() != EOF;

  printf("%d",value);
  return 0;
}
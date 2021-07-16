
#include <stdio.h>

//宏函数: 原封不动的替换（根据参数值）,不会计算的，要加上括号。而且传入的参数不要有副作用，如：a++ --b
#define MAX(a,b) (a) > (b) ? (a) : (b)

//多行宏函数
#define IS_HEX_CHARACTER(ch) \
((ch) >= '0' && (ch) <= '9') || \
((ch) >= 'A' && (ch) <= 'F') || \
((ch) >= 'a' && (ch) <= 'f')
int main(void){

  int num = MAX(3,9);
  printf("max: %d\n",num);

  printf("is Hex character: %d\n",IS_HEX_CHARACTER('P'));


  return 0;
}
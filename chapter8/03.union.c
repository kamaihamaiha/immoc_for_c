/**
 * 联合体
 * 属性是互斥的，只能有一个存在。应用场景优点复杂
 */
#include "io_utils_teacher.h"
typedef union Operand{
  int age;
  char *name;
  double money;
} Operand;



int main(){

  PRINT_INT(sizeof( Operand));

  return 0;
}
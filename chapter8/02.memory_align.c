/**
 * 内存对齐：
 * 1. #pragma pack(n) => 全局(在结构体定义的上面)
 * 2. __attribute((aligned(n))) => gcc. 没有好的效果，不知道为什么？？？
 * 3. _Alignas(n) => C11
 * 4. _Alignof(), C11
 */

#include "io_utils_teacher.h"

//#pragma pack(2) //用来设置 struct 内存对齐, 2 是对齐倍数
struct Person {
  char c0;
  char c1;
  int age;
  char c2;
} Person;

struct OptimizedPerson {
  char c0;
  char c1;
  __attribute((aligned(8))) int age;
  char c2;
} OptimizedPerson;
int main() {

  PRINT_INT(sizeof(char));
  PRINT_INT(sizeof(Person));
  PRINT_INT(sizeof(OptimizedPerson));

  return 0;
}

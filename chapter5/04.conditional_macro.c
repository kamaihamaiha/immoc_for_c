
#include <stdio.h>
//#define DEBUG
/**
 * 1. #ifdef ... #endif
 * 2. #ifndef ... #define .. #endif
 * 3. 利用 宏调试信息，两种方式
 *  1. 在 .c 代码里面定义宏：#define DEBUG
 *  2. 在 CMakeLists.txt 加上：target_compile_definitions(${name} PUBLIC DEBUG)
 * 4. 在 C++ 中兼容 C代码的宏：
 * 5. 使用系统定义的宏
 */

//在 C++ 中兼容 C代码的宏：
#ifdef __cplusplus

extern "C" {

};
#endif

void dump(char *msg) {
#ifdef DEBUG
  puts(msg);
#endif
}
int main() {

  dump("ddd");

  printf("__STDC_VERSION__: %ld\n",__STDC_VERSION__);
#if __STDC_VERSION__ >= 201112
  puts("C11");
#elif __STDC_VERSION__ >= 199901
  puts("C99");
#else
  puts("Other");
#endif
  return 0;
}
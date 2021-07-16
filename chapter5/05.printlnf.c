#include <stdio.h>
#include <stdarg.h>


void PrintLnf(const char* format, ...){
  va_list args;
  va_start(args,format);

  vprintf(format,args);
  printf("\n");
  va_end(args);
}

//解决每次都打印换行符的麻烦,能打印出 文件名、行号、方法名
//#define PRINTLNF(format, ...) printf(" ["__FILE__":%d] %s : "format" \n", __LINE__,__FUNCTION__,##__VA_ARGS__)
#define PRINTLNF(format, ...) printf(" [%s:%d] %s : "format" \n",__FILE__ ,__LINE__,__FUNCTION__,##__VA_ARGS__)

//输出变量值，自带变量名
#define PRINT_INT(value) PRINTLNF(#value": %d",value)

//自带，文件、行、函数信息

int main(void ){

  PRINTLNF("hello");
  PRINTLNF("hello");

  int x = 9;
  PRINT_INT(x);
  PRINT_INT( 9 + 99);

  return 0;
}
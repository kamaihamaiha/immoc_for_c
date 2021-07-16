#include <stdio.h>
#include <wchar.h>
#include "io_utils.h"
int main(void){

  //以 NULL \0 结尾
  char string[] = "Hello world";

  PRINT_LNF("%s",string);
  for (int i = 0; i < 11; ++i) {
    printf("%c\n",string[i]);
  }

  //中文字符串
  char string_cn = "你好";

  //宽字符
  wchar_t w_string_cn = L"宽字符";
  return 0;
}
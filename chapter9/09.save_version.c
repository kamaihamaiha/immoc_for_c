#define __STDC_WANT_LIB_EXT1__ 1
#include "io_utils_teacher.h"
#include <string.h>
#include <stdlib.h>

//了解即可
int main(){

#ifdef __stdc_lib_ext1__
  puts("支持 C11 safe version.");
#else
  puts("不支持 C11 safe version.");
#endif

  char dest[2];
  /*int error_no = strcpy_s(dest,2,"Too long!");
  PRINT_INT(error_no);
  if (error_no){
    //打印错误码
    perror("Error");
  }*/

  return 0;
}

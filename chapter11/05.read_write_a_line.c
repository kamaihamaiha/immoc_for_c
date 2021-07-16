/**
 * 读写一行字符
 * gets() C11 开始被移除了，因为不安全
 * gets_s() C11 开始引入，推荐使用. 从控制台接收一行输入，但是我的 CLion 找不到这个函数
 *
 * fgets()
 * puts()
 * fputs()
 *
 * 以上的函数都用来读取文本文件，不要读取二进制文件。
 */

#include "io_utils_teacher.h"
#include <stdio.h>
#include <string.h>

void Echo(){
  char buffer[1024];
  while (1){
    if (!fgets(buffer,1024,stdin)){
      break;
    }
    printf("%s",buffer);
  }
}

int main(){

  Echo();
  return 0;
}
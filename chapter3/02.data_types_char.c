#include <stdio.h>
#include <wchar.h>

int main(){
  //打印 ASCII 表
  for (int i = 0; i < 127; ++i) {
    printf("%c : %d\t",(char)i,i);
    if (i % 10 == 0){
      printf("\n");
    }
  }

  //'1' - 49. 下面的是转义字符，61 是 49 的八进制。\ 后面默认是 八进制。
  char one_char = '\61';
  printf("\n\n%c\n",one_char);

  //Unicode CJK：Chinese Japanese Korean. C95 开始支持 宽字符
  wchar_t center = L'中';
  printf("中：%d\n",center);

  return 0;
}


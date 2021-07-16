/**
 * 查找字符与子串
 * 1. 查找字符：strchr,strrchr
 * 2. 查找子串: strstr()
 * 3. 查找字符(按照分隔符)：strpbrk
 */


#include <io_utils_teacher.h>
#include <string.h>
int main() {

  //查找字符：strchr,strrchr
  char *hello = "Hello World!";
  char *l = strchr(hello, 'l');
  char *lr = strrchr(hello, 'l');

  puts(l);
  puts(lr);

  //查找子串: strstr()
  char *sub_string = strstr(hello,"Wo");
  puts(sub_string);
  //打印偏移
  PRINT_INT(sub_string - hello);


  //查找字符：strpbrk
  char *languages = "C, 1972; C++, 1983; Java, 1990; Rust, 2010; Kotlin, 2011";
  char *str_break = ",;";
  int count = 0;
  char *cur_p = languages;

  do {
    cur_p = strpbrk(cur_p,str_break);
    if (cur_p) {
      puts(cur_p);
      count++;
      cur_p++;
    }
  } while (cur_p);

  PRINT_INT(count);



  return 0;
}
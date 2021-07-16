/**
 * 字符串的拆分
 *  strtok()
 *   拆分后，会把拆分的位置置为 NULL
 */
#include <stdlib.h>
#include <string.h>
#include "io_utils_teacher.h"

int main() {

  char languages[] = "C, 1972; C++, 1983; Java, 1990; Rust, 2010; Kotlin, 2011";

  //分隔出来的数据放到结构体中
  typedef struct Language {
    int year;
    const char *name;
  } Language;

  const char *language_break = ";";
  const char *language_field = ",";

  //先给三个
  int language_capacity = 3;
  int language_size = 0;

  //动态申请内存
  Language *lans = malloc(sizeof(Language) * language_capacity);
  if (!lans) abort();

  char *next = strtok(languages,language_field);

  while (next){
    Language language;
    language.name = next;

    //拆分年份
    next = strtok(NULL,language_break);
    if (next){
      language.year = atoi(next);

      //判断数组容量是否够用
      if (language_size + 1 > language_capacity){
        language_capacity *= 2;
        lans = realloc(lans, sizeof(Language) * language_capacity);
        if (!lans) abort();
      }
    }

    lans[language_size++] = language;

    //继续拆分后，第一个参数传 NULL
    next = strtok(NULL,language_field);
  }

  PRINTLNF("Languages: %d",language_size);
  PRINTLNF("Language Capacity: %d",language_capacity);

  //打印结构体数组的内容
  for (int i = 0; i < language_size; ++i) {
    PRINTLNF("Language[name=%s, year=%d]",lans[i].name,lans[i].year);
  }
  return 0;
}
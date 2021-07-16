/**
 * 副作用与纯函数
 *
 * 副作用：表达式的作用是提供结果，除了表达式的值以外的影响都是副作用（如：count++）
 */

#include "io_utils_teacher.h"
#include "tinycthread.h"
#include <stdlib.h>


int Counter(void *arg){
  int local_count = 0;
  PRINTLNF("Counter.");
  for (int i = 0; i < 1000000; ++i) {
    local_count++;
  }

  return local_count;
}

int main(){

  thrd_t t_1, t_2;
  thrd_create(&t_1,Counter,NULL);
  thrd_create(&t_2,Counter,NULL);

  int count = 0;
  int res;
  thrd_join(t_1,&res);
  count += res;

  thrd_join(t_2,&res);
  count += res;

  PRINT_INT(count);

  return 0;
}
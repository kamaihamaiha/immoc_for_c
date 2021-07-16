/**
 * 线程存储期： C11 开始
 * 解释：在线程开始时初始化，在线程结束时销毁，每一个线程都有一个独立的副本
 *
 * 方式一：一个变量用 -Thread_local 修饰，就可以获得线程存储期
 * 方式二：tss_create()、tss_delete()
 */
#include "tinycthread.h"
#include "io_utils_teacher.h"
#include "time_utils.h"

_Thread_local int count = 0;

int Counter(int *step){
  for (int i = 0; i < 1000000; ++i) {
    count += *step;
  }
  PRINT_INT(count);
  return 0;
}

int main(){

  thrd_t thread_a, thread_b;
  int step_1 = 1, step_2 = 2;
  thrd_create(&thread_a, Counter, &step_1);
  thrd_create(&thread_b, Counter, &step_2);

  thrd_join(thread_a, NULL);
  thrd_join(thread_b, NULL);

  PRINT_INT(count);

  return 0;
}

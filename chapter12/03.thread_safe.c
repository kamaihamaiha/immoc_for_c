/**
 * 线程安全问题产生：
 * 1. 对共享资源进行非原子对并发访问
 * 2. 不同线程之间的代码可见行问题
 * 3. 线程内部代码编译时的重排序问题
 */
#include <stdio.h>
#include "io_utils_teacher.h"
#include "tinycthread.h"

int count = 0;

int Counter(void *arg) {
  PRINTLNF("Counter...");
  for (int i = 0; i < 999999; ++i) {
    count++;
  }
  return 0;
}

int main() {

  thrd_t thread_a, thread_b;
  thrd_create(&thread_a,Counter,NULL);
  thrd_create(&thread_b,Counter,NULL);

  thrd_join(thread_a,NULL);
  thrd_join(thread_b,NULL);

  PRINT_INT(count);

  return 0;
}
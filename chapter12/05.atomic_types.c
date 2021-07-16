/**
 * 原子类型:
 * stdatomic.h
 * atomic_int
 * atomic_is_lock_free() 是否是通过 lock 实现的原子操作，C11 开始有
 *  返回 true 表明传入的参数原子操作，是通过 CPU 指令实现的
 *  返回 false 表明传入的参数原子操作，是通过 lock 实现的
 *
 *  atomic_flag 不需要加锁
 *       atomic_flag_clear()
 *       atomic_flag_test_and_set()
 */

#include <stdatomic.h>
#include "tinycthread.h"
#include "io_utils_teacher.h"

atomic_int count = 0;

int Counter(void *arg) {
  PRINTLNF("Counter...");
  for (int i = 0; i < 999999; ++i) {
    count++;
  }
  return 0;
}
int main() {

  thrd_t thread_a, thread_b;
  thrd_create(&thread_a, Counter, NULL);
  thrd_create(&thread_b, Counter, NULL);

  thrd_join(thread_a, NULL);
  thrd_join(thread_b, NULL);

  PRINT_INT(count);

  atomic_is_lock_free();
  return 0;
}

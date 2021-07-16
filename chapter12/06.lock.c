//
#include "tinycthread.h"
#include "io_utils_teacher.h"
#include "time_utils.h"

mtx_t mutex;
int count = 0;

int Counter(void *arg) {
  PRINTLNF("Counter...");
  for (int i = 0; i < 999999; ++i) {
    mtx_lock(&mutex);
    count++;
    mtx_unlock(&mutex);
  }
  return 0;
}

int main(){

  // mtx_t 锁
  // mtx_init() 创建锁
  // mtx_destroy() 销毁锁
  // mtx_lock() 加锁
  // mtx_unlock() 解锁
  // mtx_timedlock()
  // mtx_trylock() 尝试加锁

  mtx_init(&mutex,mtx_plain);


  TimeCost(NULL);

  thrd_t thread_a, thread_b;
  thrd_create(&thread_a, Counter, NULL);
  thrd_create(&thread_b, Counter, NULL);

  thrd_join(thread_a, NULL);
  thrd_join(thread_b, NULL);

  PRINT_INT(count);

  TimeCost("duration: ");

  mtx_destroy(&mutex);

  return 0;
}

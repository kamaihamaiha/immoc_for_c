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
#include <stdlib.h>

tss_t count_key;

int count = 0;

void MyFree(void *ptr) {
  PRINTLNF("Free %#x", ptr);
  free(ptr);
}

int Counter(int *step) {
  int *count = malloc(sizeof(int));
  *count = 0;
  if (tss_set(count_key, count) == thrd_success) {
    for (int i = 0; i < 1000000; ++i) {
      *count += *step;
    }
  }
  PRINT_INT(*count);
  PRINT_INT(*(int *)tss_get(count_key));
  return 0;
}

int main() {

  if (tss_create(&count_key,MyFree) != thrd_success) {
    return -1;
  }

  thrd_t thread_a, thread_b;
  int step_1 = 1, step_2 = 2;
  thrd_create(&thread_a, Counter, &step_1);
  thrd_create(&thread_b, Counter, &step_2);

  thrd_join(thread_a, NULL);
  thrd_join(thread_b, NULL);

  puts("Thread a and thread b ended.");
  PRINT_INT(count);

  // 如果在线程执行完之前就删除，那么在 37 行 tss_create() 里的 MyFree 函数就不会调用了。
  // 「这个坑要注意★★★」，就要自己手动释放内存，而不是依靠 MyFree() 了
  tss_delete(count_key);
  PRINTLNF("count_key deleted.");

  return 0;
}

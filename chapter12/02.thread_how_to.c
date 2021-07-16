/**
 * Linux 下需要用 pthread; 在 CMakeLists.txt 操作
 */
#include <io_utils_teacher.h>
#include <stdio.h>
#include <tinycthread.h>
int SayHello(char *name){
  PRINTLNF("Run in new thread[%#x]: hello, %s",thrd_current(),name);
  return 0;
}
int main(){

  thrd_t new_thread ;
  int res = thrd_create(&new_thread,SayHello("say"),"C lang");
  if (res == thrd_success){
    PRINTLNF("Run in Main thread[%#x], created new_thread[%#x]",thrd_current(),new_thread);
  } else {
    PRINTLNF("Run in Main thread[%#x],failed created new_thread[%#x]",thrd_current());
  }

  // int res2;
  // thrd_join(new_thread,&res2); 等待 new_thread 执行完。res2 是执行结果

  // 线程让出资源
  // thrd_yield();
  return 0;
}
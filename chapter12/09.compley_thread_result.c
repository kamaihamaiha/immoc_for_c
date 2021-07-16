/**
 * 处理复杂的线程返回结果
 */

#include <stdlib.h>
#include "tinycthread.h"
#include "io_utils_teacher.h"

typedef struct ComplexResult {
  int value;
  char *b;
} ComplexResult;

typedef struct {
  int arg;
  ComplexResult res;
} ComplexArg;

int ComplexReturnValue(ComplexArg *arg){
   ComplexResult *complex_result = &(arg->res);
   complex_result->value = 1;
   complex_result->b = "name";
  return 0;
}

int main() {

  ComplexArg complex_arg = {.arg = 1};
  thrd_t t;

  // 在线程 t 里面执行函数：ComplexReturnValue(ComplexArg *arg), 参数值：&complex_arg
  thrd_create(&t,ComplexReturnValue,&complex_arg);

  thrd_join(t,NULL);

  PRINT_INT(complex_arg.res.value);
  PRINT_STRING(complex_arg.res.b);

  return 0;
}

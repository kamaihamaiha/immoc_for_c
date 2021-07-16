#include "../include/factorial.h"


/**
 * 阶乘计算
 * @param n
 * @return
 */
unsigned int Factorial(unsigned int n) {
  if (n == 0) {
    return 1;
  }
  return n * Factorial(n - 1);
}

unsigned int FactorialWithIteration(unsigned int n) {
  if (n == 0) {
    return 1;
  }
  int sum = 1;
  for (int i = 1; i < n; ++i) {
    sum *= i;
  }
  return sum;
}

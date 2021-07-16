/**
 * 函数的递归
 */

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

//f(n) = f(n-1) + f(n-2)
/**
 * 斐波那契数列：递归
 * @param x
 * @return
 */
unsigned int Fibonacci(unsigned x) {
  if (x == 1 || x == 0) {
    return x;
  } else {
    return Fibonacci(x - 1) + Fibonacci(x - 2);
  }
}

/**
 * 斐波那契数列: 迭代
 * @param x
 * @return
 */
unsigned int FibonacciWithIterator(unsigned x){
  if (x == 0 || x == 1){
    return x;
  }
  int current = 1;
  int last = 0;
  for (int i = 0; i <= x - 2; ++i) {
    int temp = current;
    current += last;
    last = temp;
  }
  return current;
}

#include <stdio.h>
int main(void) {

  int num = 10;
  printf("%d 的阶乘：%d\n", num, Factorial(num));
  printf("%d Fibonacci：%d\n", num, Fibonacci(num));
  printf("%d Fibonacci：%d\n", num, FibonacciWithIterator(num));
}
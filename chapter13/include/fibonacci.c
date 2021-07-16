#include "fibonacci.h"

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

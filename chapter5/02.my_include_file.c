#include <stdio.h>
//#include "include//factorial.h"
#include <factorial.h>

int main(void) {

  int x = 9;
  for (int i = 0; i < x; ++i) {
    printf("%d! = %d\n", i, Factorial(i));

  }
  return 0;
}




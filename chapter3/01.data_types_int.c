#include <stdio.h>
#include <limits.h>
int main(){
  // hd%: short decimal
  // hu%: unsigned short decimal
  // %d: decimal
  // %ld: long decimal
  // %lld: long long decimal
  // %u: unsigned decimal
  // %x: hex
  // %o: oct

  /*printf("The size of short int: %d\n", sizeof(short int));
  printf("The size of int: %d\n", sizeof(int));
  printf("The size of long int: %d\n", sizeof(long int));
  printf("long: %d\n", sizeof(long));
  printf("long long: %d\n", sizeof(long long));
  printf("The max int value is: %d\n",INT_MAX);
  printf("The min int value is: %d\n",INT_MIN);
  printf("unsigned max int: %u\n",UINT_MAX);
*/
  size_t size_of_int = sizeof(int );
  int x = 3;

  // %#x 以 0xe885b2bc 方式显示十六进制
  printf("address of x: %#x\n",&x);
  return 0;
}
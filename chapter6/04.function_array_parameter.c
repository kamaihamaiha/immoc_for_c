
#include <stdio.h>
#define LENGTH 5

/**
 *
 * @param arr 只会把数组的首地址传入进去
 * @param length
 * @return
 */
int SumIntArray(int arr[],int length){
  int sum = 0;
  for (int i = 0; i < LENGTH; ++i) {
    sum += arr[i];
  }

  return sum;
}
int main(void){

  int arr[] = {1,2,3,4,5};
  int sum = SumIntArray(arr,5);
  printf("%d\n",sum);

  return 0;
}

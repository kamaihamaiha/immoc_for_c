/**
 * 指针版快速排序
 */

#include <io_utils_teacher.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void GetIntArray(int size, int *arr) {
  for (int i = 0; i < size; ++i) {
    *(arr + i) = i;
  }
}

void SwapInt(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

//打乱数组
void ShuffleArray(int *arr, int length) {
  //得到随机数
  srand(time(NULL));
  for (int i = length - 1; i > 0; i--) {
    int random_num = rand() % i;
    SwapInt(arr + i, arr + random_num);
  }
}

/**
 * 得到新的切分位置
 * @param low
 * @param high
 * @return
 */
int *Partition(int *low, int *high) {
  int pivot = *(low + (high - low) / 2);
  int *left = low;
  int *right = high;

  while (1) {
    while (*left < pivot) left++;
    while (*right > pivot) right--;

    if (left >= right) break;

    //swap
    SwapInt(left, right);
  }

  return left; //or right
}

void QuickSort(int *low, int *high) {
  if (low >= high) return;
  int *partition = Partition(low, high);
  QuickSort(low, partition);
  QuickSort(partition + 1, high);
}

#define ARR_SIZE  20
int main() {

  int *my_arr = malloc((sizeof (int)) * ARR_SIZE);
  GetIntArray(ARR_SIZE,my_arr);
  PRINT_INT_ARRAY(my_arr,ARR_SIZE);
  ShuffleArray(my_arr,ARR_SIZE);


  printf("\n排序前：\n");
  PRINT_INT_ARRAY(my_arr,ARR_SIZE);

  QuickSort(my_arr,my_arr + ARR_SIZE - 1);
  printf("排序后：\n");
  PRINT_INT_ARRAY(my_arr,ARR_SIZE);

  free(my_arr);
  return 0;
}
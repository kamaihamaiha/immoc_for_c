//
// 数组快速排序：Lomuto 分割法
//
#include "io_utils_teacher.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * 快速排序. 时间复杂度：n log n
 * @param arr
 * @param low
 * @param high
 * @param step
 */
void SortQuick(int *arr, int low, int high, int *step) {
  if (low >= high) {
    return;
  }
  int pivot = arr[high];
  int l = low;
  int r = high;
  int partition;

  while (l < r) {
    while (arr[l] < pivot) { //左边的点一直往右移动，直到找到了大于 pivot 的数
      l++;
      (*step)++;
    }

    while (arr[r] > pivot) { //右边的点一直往左移动，直到找到了小于 pivot 的数
      r--;
      (*step)++;
    }

    //交换 r 和 l 位置的两个数
    int temp = arr[l];
    arr[l] = arr[r];
    arr[r] = temp;
  }

  //此时 l == r 了
  partition = l;
  //or partition = r;

  //将 pivot 的数拿过来
  arr[partition] = pivot;

  SortQuick(arr, low, partition - 1, step);
  SortQuick(arr, partition + 1, high, step);

}

void SwapElements(int arr[], int first, int second) {
  int temp = arr[first];
  arr[first] = arr[second];
  arr[second] = temp;
}

//打乱数组
void ShuffleArray(int arr[], int length) {
  //得到随机数
  srand(time(NULL));
  for (int i = length - 1; i > 0; i--) {
    int random_num = rand() % i;
    SwapElements(arr, i, random_num);
  }
}

/**
 * 冒泡排序
 * @param arr
 * @param length
 * @param step 耗用步数
 */
void PopSort(int arr[], int length, int *step) {
  if (length == 1) {
    return;
  }
  for (int i = 0; i < length - 1; ++i) {

    for (int j = i + 1; j < length; ++j) {
      if (arr[i] > arr[j]) {
        //swap arr element
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
      (*step)++;
    }
  }
}

#define ARR_SIZE 1000
int main(void) {

  int arr[ARR_SIZE] = {};

  int size = sizeof(arr) / sizeof(arr[0]);
//  printf("size of arr: %d\n",size);

  for (int i = 0; i < size; ++i) {
    arr[i] = i;
  }

  ShuffleArray(arr, size);

  int step = 0;
  SortQuick(arr, 0, size - 1, &step);

  PRINT_INT_ARRAY(arr, size);
  PRINT_INT(step);

  step = 0;
  ShuffleArray(arr, size);
  PopSort(arr, size, &step);
  PRINT_INT_ARRAY(arr, size);
  PRINT_INT(step);

  return 0;
}


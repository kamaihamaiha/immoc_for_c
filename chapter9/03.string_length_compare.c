/**
 * 字符串 长度、比较
 *
 */
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "io_utils_teacher.h"

void Swap(char **x, char **y) {
  char *temp = *x;
  *x = *y;
  *y = temp;
}

void SwapInt(int *x, int *y) {
  int temp = *x;
  *x = *y;
  *y = temp;
}

char **Partition(char **low, char **high) {
  //找一个切分点, 如：中间位置的数
  char *pivot = *(low + (high - low) / 2);
  char **left = low;
  char **right = high;

  while (1) {
    while (strcmp(*left, pivot) < 0) left++;
    while (strcmp(*right, pivot) > 0) right--;
    if (left >= right) break;
    Swap(left, right);
  }

  return left;
}

void QuickSort(char **low, char **high) {
  if (low >= high) return;
  char **partition = Partition(low, high);
  QuickSort(low, partition);
  QuickSort(partition + 1, high);
}

//生成一个 int 数组
void GetIntArray(int size, int *arr) {

  for (int i = 0; i < size; ++i) {
    *(arr + i) = i;
  }
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

int main() {

  char *str = "Hello Guy!";
  //strlen() 会一个个数，字符串太长了，就不安全了
  PRINT_INT(strlen(str));

  //C11 增加了安全版本
  PRINT_INT(strnlen(str, 20));

  //比较字符串
  char *left = "12345";
  char *right = "123one_two_three_four_five";

  PRINT_INT(strcmp(left, right));

  //比较前 3 个字符
  PRINT_INT(strncmp(left, right, 3));

  //排序字符串数组：演员名单
  char *staffs[] = {
      "Cindy",
      "Don",
      "Andrey",
      "Elsa",
      "George",
      "Frank",
      "Benny"
  };

  QuickSort(staffs, staffs + 6);

  PRINT_ARRAY("%s, ", staffs, 7);

  return 0;
}
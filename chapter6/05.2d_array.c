//二维数组
#include <stdio.h>
#include "io_utils_teacher.h"

void SumIntArray(int rows, int columns, int array[][columns], int result[]) {
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < columns; ++j) {
      result[i] += array[i][j];
    }
  }
}
int main(void) {

  int vehicle_limits[5][2] = {
      {1, 4},
      {2, 3},
      {5, 9},
      {6, 0},
      {7, 8}
  };

  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 2; ++j) {
      printf("%d,", vehicle_limits[i][j]);
    }
    printf("\n");
  }

  int scores[5][3] = {
      {100, 120, 140},
      {130, 140, 120},
      {121, 103, 90},
      {141, 120, 99},
      {134, 120, 105}
  };

  int s_res[] = {0}; //初始化
  SumIntArray(5, 3, scores, s_res);

  PRINT_INT_ARRAY(s_res, 5);
  return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <io_utils_teacher.h>

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
    SwapElements(arr,i,random_num);
  }
}

#define PLAYER_COUNT  50
int main(void) {

  int players[PLAYER_COUNT];
  for (int i = 0; i < PLAYER_COUNT; ++i) {
    players[i] = i;
  }

  ShuffleArray(players,50);
  PRINT_INT_ARRAY(players,50);

  return 0;
}


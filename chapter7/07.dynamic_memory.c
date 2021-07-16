/**
 * 动态内存分配
 * malloc
 * calloc: 直接将分配的内存内容清零
 * realloc:
 *
 * 内存分配会出现失败的情况：
 *  申请完，要进行判断。
 *
 *  常见的指针使用错误：
 *  1. 忘记释放内存
 *  2. 使用了已经释放的内存
 *  3. 使用了超出边界的内存
 *  4. 改变内存的指针，导致无法正常释放
 *
 *  动态内存使用建议：
 *  1. 避免修改指向已经分配的内存的指针
 *  2. 对于 free 之后的指针，主动置为 NULL
 *  3. 避免将过多的指针指向动态分配的内存
 *  4. 谁分配谁释放原则
 */

#include <stdio.h>
#include <io_utils_teacher.h>
#include <stdlib.h>

#define PLAYER_COUNT 10

/**
 * 初始化申请的内存区域的值
 * @param ptr
 * @param length
 * @param default_value
 */
void InitPointer(int **ptr,int length,int default_value){
  *ptr = malloc(sizeof(int) * length);
  for (int i = 0; i < length; ++i) {
    (*ptr)[i] = default_value;
  }
}

int main(void){

  //申请的内存在堆区,要手动释放
  int *players = malloc(sizeof(int) * PLAYER_COUNT);
  players = calloc(PLAYER_COUNT, sizeof(int ));
  //释放
  free(players);
  return 0;
}
/**
 * 汉诺塔
 */
#include <stdio.h>

/**
 * 汉诺塔
 * @param count
 * @param src A 柱
 * @param temp B 柱
 * @param dest C 柱
 */
void Hanoi(unsigned int count, char src, char temp, char dest, int *total_step, int print_flag) {
  if (count == 0) {
    return;
  }
  if (count == 1) {
    if (print_flag) {
      printf("%c ---> %c\n", src, dest);
    }
    (*total_step)++;
  } else {
    Hanoi(count - 1, src, dest, temp, total_step,print_flag);
    Hanoi(1, src, temp, dest, total_step,print_flag);
    Hanoi(count - 1, temp, src, dest, total_step,print_flag);
  }

}

int main(void) {

  int a = 0;
  int *step = &a;

  int level = 30;
  for (int i = 1; i <= level; ++i) {
    Hanoi(i, 'A', 'B', 'C', step,0);
    printf("塔层 %d 总共需要步数：%d\n", i,*step);
    *step = 0;
  }

  return 0;
}
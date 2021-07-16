#include "io_utils_teacher.h"
#include <ctype.h>
int main(){

  PRINT_INT(isdigit('3'));
  PRINT_INT(isdigit('0'));
  PRINT_INT(isalpha('0'));
  PRINT_INT(ispunct('0'));

  tolower(4);
  toupper(5);
  return 0;
}
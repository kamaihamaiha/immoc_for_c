
#include "io_utils_teacher.h"

//枚举实际上是从 0 开始的整数，也可以自己给赋值（但 C++ 不可以给赋值）
typedef enum FileFormat {
  PNG = 100, JPEG, BMP, UNKNOWN
} FileFormat;

FileFormat GuessFormat(char *file_path) {
  //"rb" b在 windows 下必须，在 Linux 和 Mac 上不必须
  FILE *file = fopen(file_path, "r");
  FileFormat file_format = UNKNOWN;

  if (file) {
    char buffer[8] = {0};
    size_t bytes_count = fread(buffer, 1, 8, file);
    if (bytes_count == 8) {
      // bmp: 42 4D
      // png: 89 50 4E 47 0D 0A 1A 0A
      // jpeg: FF D8 FF E0
      if ((*((short *)buffer)) == 0x4D42) {
        file_format = BMP;
      } else if ((*(long long *)buffer) == 0x0A1A0A0D474E5089){
        file_format = PNG;
      } else if (*(int *) buffer == 0xE0EFD8FF) {
        file_format = JPEG;
      }
    }
    fclose(file);
  }

  return file_format;
}

int main() {

  FileFormat file_format = UNKNOWN;
  PRINT_INT(GuessFormat("./imgs/c.bmp"));
  PRINT_INT(GuessFormat("./imgs/c0.jpeg"));
  PRINT_INT(GuessFormat("./imgs/lamp.png"));
  return 0;
}
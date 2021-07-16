
#ifndef IMOOC_FOR_C_CHAPTER6_INCLUDE_IO_UTILS_H_
#define IMOOC_FOR_C_CHAPTER6_INCLUDE_IO_UTILS_H_

#define PRINT_LNF(format, ...) printf("("__FILE__":%d) %s: "format"\n", __LINE__, __FUNCTION__,##__VA_ARGS__)

#define PRINT_INT(value) PRINT_LNF(#value": %d",value)


#define PRINT_DOUBLE(value) PRINT_LNF(#value": %lf",value)

#define PRINT_CHAR(value) PRINT_LNF(#value": %c",value)
#endif //IMOOC_FOR_C_CHAPTER6_INCLUDE_IO_UTILS_H_



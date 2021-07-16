// 结构体
//
//
#include "io_utils_teacher.h"

typedef struct Company {
  char *name;
  char *id;
  char *location;
} Company;

typedef struct Person {
  int age;
  char *name;
  char *id;
  Company *com1;
  Company com2;

  struct Person *my_self;
} Person;

struct MyInt {
  int *num;
  int x;
  int y;
  int z;
} MyInt;

int main() {

  //一次性使用
  struct {
    char *name;
  } anonymous_person;

  anonymous_person.name = "Jam";

  //初始化结构体。（. 是成员选择运算符，优先级很高）
  Person p1 = {.name="Hun", .age = 9, .id = "888"};

  PRINT_INT(p1.age);

  struct Person *p_person = &p1;
  p_person->name;

  PRINT_INT(sizeof(struct Person));
  PRINT_INT(sizeof(int));
  PRINT_INT(sizeof(char *));

  struct Company company1 = {.id = "8", .name = "Google", .location = "HongKong"};
  Person p2 = {.name = "p2", .age = 2, .id = "98932", .com1 = &company1, .com2 = {
      .id = "3",
      .name = "BMW",
      .location = "NewYork"
  }};

  p2.com2.location;
  p2.com1->location;

  PRINT_INT(sizeof(MyInt));
  return 0;
}
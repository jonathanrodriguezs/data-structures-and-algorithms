#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
  char nickname[50];
  char language[10];
  int age;
} Developer;

void print_struct(Developer dev);

int main(void)
{
  // Statical allocation in stack
  Developer linus = {"torvalds", "C", 40};
  Developer *p = &linus;
  (*p).age = 20; // dot operator
  print_struct(linus);

  // Dynamic allocation in heap
  Developer *me;
  me = (Developer *)malloc(sizeof(Developer));
  strcpy(me->nickname, "jonathan");
  strcpy(me->language, "JS");
  me->age = 30;
  print_struct(*me);

  return 0;
}

void print_struct(Developer dev)
{
  printf("Nickname: %s\n", dev.nickname);
  printf("Language: %s\n", dev.language);
  printf("Age: %d\n\n", dev.age);
}

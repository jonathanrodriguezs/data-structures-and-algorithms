#include <stdio.h>

void add(int a, int b);
void sub(int a, int b);
void mul(int a, int b);

int main(void)
{
  void (*func_ptrs[])(int, int) = { add, sub, mul };
  unsigned int a = 10, b = 40, option;

  printf("Function to execute: ");
  scanf("%d", &option);

  if (option > 2) return 1;
  (*func_ptrs[option])(a, b);
	
  return 0;
}

void add(int a, int b)
{
  printf("%d + %d = %d", a, b, a + b);
}

void sub(int a, int b) {
  printf("%d - %d = %d", a, b, a + b);
}

void mul(int a, int b) {
  printf("%d * %d = %d", a, b, a * b);
}


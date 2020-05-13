#include <iostream>

void swap_by_value(int a, int b);
void swap_by_address(int *a, int *b);
void swap_by_reference(int &a, int &b);

int main(void)
{
  int x = 10;
  int y = 50;

  swap_by_value(x, y);
  swap_by_address(&x, &y);
  swap_by_reference(x, y);

  return 0;
}

// useless swaps the formal parameters in the stack frame
void swap_by_value(int a, int b)
{
  int temp = a;
  a = b;
  b = temp;
}

// Swaps actual parameters using pointers
void swap_by_address(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

// Swaps the actual parameters using references
void swap_by_reference(int &a, int &b)
{
  int temp = a;
  a = b;
  b = temp;
}

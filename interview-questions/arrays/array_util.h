#include <stdio.h>

void print_array(int *array, int size)
{
  for (int i = 0; i < size; i++)
    printf("A[%d] = %d \n", i, *array++);
}

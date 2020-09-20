#include <stdio.h>

void print_array(int *array, int size)
{
  for (int i = 0; i < size; i++)
    printf("A[%d] = %d \n", i, *array++);
}

void swap(int *ptr1, int *ptr2)
{
  int temp;
  temp = *ptr1;
  *ptr1 = *ptr2;
  *ptr2 = temp;
}

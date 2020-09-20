#include <stdio.h>
#include "array_util.h"
#define N 10

int remove_duplicates(int *nums, int nums_size);

int main(void)
{
  int nums[N] = {1, 1, 2, 3, 3, 3, 4, 4, 5, 6};
  int n = remove_duplicates(nums, N);
  print_array(nums, n);
  return 0;
}

int remove_duplicates(int *nums, int nums_size)
{
  int *array = nums++;
  int stored = *array, new_size = 1;

  for (int i = 0; i < nums_size; i++, array++)
  {
    int current = *array;
    if (current != stored)
    {
      *nums = stored = current;
      nums++;
      new_size++;
    }
  }

  return new_size;
}

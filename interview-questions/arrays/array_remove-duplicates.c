#include <stdio.h>
#include "array_util.h"
#define N 10

int remove_duplicates(int nums[], int nums_size)
{
  if (nums_size == 0)
    return 0;

  int stored = nums[0], new_size = 1;
  for (int i = 0; i < nums_size; i++)
  {
    int current = nums[i];
    if (current != stored)
      nums[new_size++] = stored = current;
  }

  return new_size;
}

int main(void)
{
  int nums[N] = {1, 1, 2, 3, 3, 3, 4, 4, 5, 6};
  int n = remove_duplicates(nums, N);
  print_array(nums, n);
  return 0;
}

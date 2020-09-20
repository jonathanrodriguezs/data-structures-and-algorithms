#include <stdio.h>
#include "array_util.h"
#define N 4

void rotate(int nums[], int nums_size, int k)
{
}

int main(void)
{
  int nums[N] = {-1, -100, 3, 99};
  rotate(nums, N, 2);
  // Expected nums to be [3,99,-1,-100]
  print_array(nums, N);
  return 0;
}

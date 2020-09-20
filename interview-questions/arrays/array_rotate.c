#include <stdio.h>
#include "array_util.h"
#define N 4

void rotate(int nums[], int nums_size, int k)
{
  k = k % nums_size;
  int count = 0;
  for (int i = 0; count < nums_size; i++)
  {
    int current = i;
    int prev = nums[current];
    do
    {
      int next = (current + k) % nums_size;
      int temp = nums[next];
      nums[next] = prev;
      prev = temp;
      current = next;
      count++;
    } while (current != i);
  }
}

int main(void)
{
  int nums[N] = {-1, -100, 3, 99};
  rotate(nums, N, 2); // Expected: [3,99,-1,-100]
  print_array(nums, N);
  return 0;
}

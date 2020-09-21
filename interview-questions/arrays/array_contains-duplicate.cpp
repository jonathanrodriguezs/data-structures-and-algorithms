#include <iostream>
#include <vector>
#include <algorithm>

#define N 5

bool contains_duplicate(std::vector<int> &nums)
{
  if (nums.empty())
    return 0;

  std::sort(nums.begin(), nums.end());

  for (int i = 0; i < nums.size() - 1; i++)
    if (nums[i] == nums[i + 1])
      return true;

  return false;
}

int main(void)
{
  int nums[N] = {1, 2, 3, 1, 5};
  std::vector<int> nums_vector(nums, nums + N);
  bool has_dup = contains_duplicate(nums_vector);
  std::cout << "Has duplicate? " << (has_dup ? "true" : "false") << std::endl;
  return 0;
}

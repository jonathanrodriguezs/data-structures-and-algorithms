/*
 * Memory addresses for an int array:
 * Demonstrate that array elements are stored at contiguous locations
 */

#include <stdio.h>

int main()
{
  int array[5];
  printf("Size of integer in this compiler is %lu\n", sizeof(int));
  for (int i = 0; i < 5; i++)
    printf("Address array[%d] is %p\n", i, &array[i]);
  return 0;
}

/*
Sample output:
	Size of integer in this compiler is 4
	Address arr[0] is 0x7ffe64d52150
	Address arr[1] is 0x7ffe64d52154
	Address arr[2] is 0x7ffe64d52158
	Address arr[3] is 0x7ffe64d5215c
	Address arr[4] is 0x7ffe64d52160
*/
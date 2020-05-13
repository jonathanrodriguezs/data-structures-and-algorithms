#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5

int *generate_array(int n);
void fill_array(int A[], int n);
void print_array(int A[], int n);

int main(void)
{
  int *A = generate_array(N);
  int B[N] = {1, 2, 3, 4, 5};

  print_array(A, N);
  print_array(B, N);
  return 0;
}

// Returns the pointer to a filled array of n size
int *generate_array(int n)
{
  int *p = (int *)malloc(n * sizeof(int));
  fill_array(p, n);
  return p;
}

// Fill an array A of n size with random integers
void fill_array(int A[], int n)
{
  srand(time(NULL));
  for (int i = 0; i < n; i++)
  {
    A[i] = rand() % 10;
  }
}

// Prints array elements in stdout
void print_array(int A[], int n)
{
  for (int i = 0; i < n; i++)
  {
    printf("%d ", A[i]);
  }
  printf("\n");
}

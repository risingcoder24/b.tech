#include <stdio.h>
#include <omp.h>

void vectorScalarAdd(int *vector, int scalar, int size)
{
#pragma omp parallel for
  for (int i = 0; i < size; i++)
  {
    vector[i] += scalar;
  }
}

int main()
{
  int size = 10;
  int scalar = 5;
  int vector[size];

  // Initialize the vector
  for (int i = 0; i < size; i++)
  {
    vector[i] = i;
  }

  printf("Vector before addition:\n");
  for (int i = 0; i < size; i++)
  {
    printf("%d ", vector[i]);
  }
  printf("\n");

  vectorScalarAdd(vector, scalar, size);

  printf("Vector after addition:\n");
  for (int i = 0; i < size; i++)
  {
    printf("%d ", vector[i]);
  }
  printf("\n");

  return 0;
}

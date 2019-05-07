#include <stdio.h>

double sum(int n, double A[])
{
  int i;
  double x = 0.0;
  for (i=0; i<n; i++) {
    x += A[i];
  }
  return x;
}

int main()
{
  double A[10] = {1.0, 2.0, 3.0, 4.0, 5.0,
                  6.0, 7.0, 8.0, 9.0, 10.0};

  printf("sum = %lf\n", sum(10, A));
  return 0;
}

#include <stdio.h>

double sum(double A[]) // 引数が実数の配列
{
  int i;
  double x;
  x = 0.0;
  for (i=0; i<10; i++) {
    x += A[i];
  }
  return x;
}

int main()
{
  double A[10] = {1.0, 2.0, 3.0, 4.0, 5.0,
                  6.0, 7.0, 8.0, 9.0, 10.0};

  printf("sum = %lf\n", sum(A)); // [] は付けない
  return 0;
}

#include<stdio.h>
#include<stdlib.h>

typedef double* row_vector;

int main()
{
  row_vector A;
  int i, n;
  scanf("%d", &n);
  A = malloc(n * sizeof(double)); // 実数 n 個分の領域を確保してそのアドレスを A に代入

  for (i=0; i<n; i++) A[i] = (double)i;
  free(A); // 使わなくなった領域を開放する
  return 0;
}

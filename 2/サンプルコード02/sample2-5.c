#include<stdio.h>
#include<stdlib.h>

#define NEW(p,n) {p = malloc((n)*sizeof(p[0]));} // メモリ確保のマクロ(関数のようなもの)

typedef double* row_vector;

int main()
{
  row_vector A;
  int i, n;
  scanf("%d", &n);
  NEW(A, n); // 実数 n 個分の領域を確保してそのアドレスを A に代入

  for (i=0; i<n; i++) A[i] = (double)i;
  free(A); // 使わなくなった領域を開放する
  return 0;
}

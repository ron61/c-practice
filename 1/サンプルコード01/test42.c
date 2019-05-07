/* test42.c */

#include<stdio.h>

int main()
{
  int i, n, x;

  n = 10;
  x = 0;
  i=1;
  while (1) {  // 1 は条件が真であることを意味する (無限ループ)
    if (i > n) {
      break; // whileループから出る
    }
    x = x + i;
    i++;
  }
  printf("x = %d\n",x);
  return 0;
}

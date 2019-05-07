/* test41.c */

#include<stdio.h>

int main()
{
  int i, n, x;

  n = 10;
  x = 0;
  i=1;
  while (i<=n) {
    x = x + i;
    i++;
  }
  printf("x = %d\n",x);
  return 0;
}

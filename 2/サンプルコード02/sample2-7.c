#include<stdio.h>

#define N 3 // ’è”‚Ì’è‹`

int main()
{
  int i;
  double x;
  double B[N];
  for (i=1; i<=10000; i++) {
    B[i] = (double)i;
    printf("B[%d] = %lf\n", i, B[i]);
  }
  return 0;
}

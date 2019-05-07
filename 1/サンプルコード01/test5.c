/* test5.c */

#include <stdio.h>

int main()
{
  int i, n, x;

  scanf("%d", &n); // キーボードから入力した値を変数 n に入れる
                   //  & を忘れないように
  x = 0;
  for (i=1; i<=n; i++) {
    x = x + i;
  }
  printf("x = %d\n",x);
  return 0;
}

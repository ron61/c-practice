/* test7.c */

#include <stdio.h>

int sum(int n) // 引数が整数 n で，整数を返す関数 sum の定義
{
  int i, x; // これらの変数は main 内のものとは無関係
  x = 0;
  for (i=1; i<=n; i++) {
    x = x + i;
  }
  return x;
}

int main() // main 自体も関数である
{
  int n, x;
  scanf("%d", &n);
  x = sum(n); // 関数を呼び出し，結果を x に入れる
  printf("x = %d\n",x);
  return 0;
}

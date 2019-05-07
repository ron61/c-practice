/* test6.c */

#include <stdio.h>
#include <stdlib.h> // おまじない

int main(int argc, char *argv[]) // 引数の数が argc 個，argv[] が引数の文字列の配列
{                                // argv[0] にはプログラムの名前が入っている
  int n;
  double x; // 実数の変数
  if (argc < 4) exit(1); // 引数が足りない
  printf("%s %s %s %s\n", argv[0], argv[1], argv[2], argv[3]); // 引数の文字列を全て表示
  n = atoi(argv[2]); // 文字列を整数に
  x = atof(argv[3]); // 文字列を実数に
  printf("%s %d %lf\n", argv[1], n, x); // 文字列 整数 実数を表示し，改行する
  return 0;
}

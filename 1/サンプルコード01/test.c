/* test.c */
    //   /*  ... */ で囲まれた部分はコメント
    //   行の末尾までコメント

#include <stdio.h> // とりあえずはおまじないと思う

int main() // C 言語は main() から実行が始まる．{...} の中が実行される
{
  printf("Hello.\nI am Kunihiko Sadakane.\n"); // 画面に文字列を表示．命令の末尾には ; をつける
  return 0; // 正常終了の場合は 0 を返す
}

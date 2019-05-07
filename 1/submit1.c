#include <stdio.h>

int CalcSumOfSquares(int n){
    int sum = 0;
    if(n < 1){
        return 0;
    } else{

    for (int i=0; i <=n; i ++){
        sum += i * i;
    }
    return sum;
    }
}

int main()
{
  int n;
  scanf("%d", &n);
  int sum = 0;
  sum = CalcSumOfSquares(n);
  
  printf("%d", sum);
  return 0;
}

#include<stdio.h>
#include<stdlib.h>

typedef double* row_vector;

int main()
{
  row_vector A;
  int i, n;
  scanf("%d", &n);
  A = malloc(n * sizeof(double)); // ���� n ���̗̈���m�ۂ��Ă��̃A�h���X�� A �ɑ��

  for (i=0; i<n; i++) A[i] = (double)i;
  free(A); // �g��Ȃ��Ȃ����̈���J������
  return 0;
}

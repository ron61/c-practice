#include<stdio.h>
#include<stdlib.h>

#define NEW(p,n) {p = malloc((n)*sizeof(p[0]));} // �������m�ۂ̃}�N��(�֐��̂悤�Ȃ���)

typedef double* row_vector;

int main()
{
  row_vector A;
  int i, n;
  scanf("%d", &n);
  NEW(A, n); // ���� n ���̗̈���m�ۂ��Ă��̃A�h���X�� A �ɑ��

  for (i=0; i<n; i++) A[i] = (double)i;
  free(A); // �g��Ȃ��Ȃ����̈���J������
  return 0;
}

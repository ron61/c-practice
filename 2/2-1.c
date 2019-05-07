#include<stdio.h>
#include<stdlib.h>

#define NEW(p,n) {p = malloc((n)*sizeof(p[0]));}

typedef double* row_vector;
typedef row_vector* matrix;

row_vector create_row_vector(int m)
{
  int i;
  row_vector V;
  NEW(V, m);
  for (i=0; i<m; i++) V[i] = 0.0;
  return V;
}

matrix create_matrix(int n,int m)
{
    int i;
    matrix M;
    NEW(M, n)
    for(i = 0;i < n;i ++)
    {
        NEW(M[i],m)
        M[i] = create_row_vector(m);
    }
    return M;
}

matrix transpose_matrix(int n,int m,matrix A,matrix B)
{
    
}

void read_matrix(int n,int m,matrix A)
{
    for(int i = 0;i < n;i ++)
    {
        for (int j = 0;j < m;j ++)
        {
            scanf("%lf ", &A[i][j]);
        }
    }
}

void print_matrix(int n,int m,matrix B)
{
    printf("%d %d\n", m, n);

    for(int column = 0;column < m;column ++)
    {
        for (int row = 0;row < n;row ++)
        {
            printf("%lf ", B[column][row]);
        }
        printf("\n");
    }
}

int main()
{
    matrix A,B;
    int n, m;
    scanf("%d %d", &n,&m);

    A = create_matrix(n, m);
    B = create_matrix(m, n);
    
    read_matrix(n, m, A);
    transpose_matrix(n, m, A, B);
    print_matrix(n, m, B);
    
    free(A);
    return 0;
}

/*
#include<stdio.h>
#include<stdlib.h>

#define NEW(p,n) {p = malloc((n)*sizeof(p[0]));}

typedef double* row_vector;
typedef row_vector* matrix;

row_vector create_row_vector(int m)
{
  int i;
  row_vector V;
  NEW(V, m);
  for (i=0; i<m; i++) V[i] = 0.0;
  return V;
}

matrix create_matrix(int n,int m)
{
    int i;
    matrix M;
    NEW(M, n)
    for(i = 0;i < n;i ++)
    {
        NEW(M[i],m)
        M[i] = create_row_vector(m);
    }
    return M;
}

matrix transpose_matrix(int n,int m,matrix A,matrix B)
{

}

void read_matrix(int n,int m,matrix A)
{
    for(int i = 0;i < n;i ++)
    {
        for (int j = 0;j < m;j ++)
        {
            scanf("%lf ", &A[i][j]);
        }
    }
}

void print_matrix(int n,int m,matrix A)
{
    printf("%d %d\n", m, n);

    for(int column = 0;column < m;column ++)
    {
        for (int row = 0;row < n;row ++)
        {
            printf("%lf ", A[row][column]);
        }
        printf("\n");
    }
}

int main()
{
    matrix A,B;
    int n, m;
    scanf("%d %d", &n,&m);

    A = create_matrix(n, m);
    B = create_matrix(m, n);
    
    read_matrix(n, m, A);
    
    print_matrix(n, m, A);
    
    free(A);
    return 0;
}

*/

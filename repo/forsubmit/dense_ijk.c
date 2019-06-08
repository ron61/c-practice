#include<stdio.h>
#include<stdlib.h>

#define NEW(p,n) {p = malloc((n)*sizeof(p[0]));}

typedef double* row_vector;
typedef row_vector* matrix;

row_vector create_row_vector(int m) {
  int i;
  row_vector V;
  NEW(V, m);
  for (i=0; i<m; i++) V[i] = 0.0;
  return V;
}

matrix create_matrix(int n,int m) {
    int i;
    matrix M;
    NEW(M, n)
    for(i = 0;i < n;i ++) {
        NEW(M[i],m)
        M[i] = create_row_vector(m);
    }
    return M;
}

matrix square_matrix(int n,int m,matrix A) {
    matrix M;
    M = create_matrix(n,m);
    double x;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            x = 0;
            for (int k = 0; k < n; k++) {
                x += A[i][k] * A[k][j];
            }
            M[i][j] = x;
        }
    }
    return M;
}

void read_matrix(int n,int m,matrix A) {
    int row;
    double x;

    for(int i = 0;i < n;i ++) {
        while(1) {
            scanf("%d", &row);
            if (row < 0) break;
            row --;
            scanf("%lf",&x);
            A[i][row] = x;
        }
    }
}

void print_matrix(int n,int m,matrix M) {
    int j;
    printf("%d %d\n", m, n);

    for (int i = 0; i < n; i++) {
        j = 0;
        for (int j = 0; j < n; j++) {
            if(M[i][j] != 0) {
                printf("%2d ",j+1);
                printf("%3.2lf  ",M[i][j]);
            }
        }
        printf("-1\n");
    }
}

int main() {
    matrix A,B;
    int n, m;
    scanf("%d %d", &n,&m);

    A = create_matrix(n, m);
    B = create_matrix(m, n);
    
    read_matrix(n, m, A);
    B = square_matrix(n,m,A);
    print_matrix(n, m, B);
    
    free(A);
    free(B);
    return 0;
}

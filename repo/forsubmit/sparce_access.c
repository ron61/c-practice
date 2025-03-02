#include <stdio.h>
#include <stdlib.h>
#define NEW(p,n) {p = malloc((n)*sizeof(p[0])); if ((p)==NULL) {printf("not enough memory¥n"); exit(1);};}

#pragma region typedef
typedef struct slobj_  {
    struct slobj_* next; // 後の要素へのポインタ
    int j; // j列目　
    double v; // (i,j)要素
}* slobj;

typedef struct  {
    slobj head; // 先頭要素のポインタ
    slobj tail; // 末尾要素のポインタ
}* slist;

typedef struct  {
    int n,m;
    slist* A;
}* smatrix;

#pragma endregion

slobj slobj_new(int j,double x) {
    slobj p;
    NEW(p,1);
    p->j = j;
    p->v = x;
    p->next = NULL;
    return p;
}

#pragma region slist
 
slist slist_new(void) {
    slist L;
    NEW(L,1);
    L->head = NULL;
    L->tail = NULL;
    
    return L;
}

void slist_insert_head(slist L, slobj p)  { 
    p->next = L->head; 
    L->head = p; 
}

void slist_insert_tail(slist L, slobj r) {
    if(L->head == NULL)
    {
        L->head = r;
        L->tail = r;
    }
    else
    {
        L->tail->next = r;
        L->tail = r;
    }
}

void slist_free(slist L) {
    slobj p, q;
    p = L->head;
    while (p != NULL) 
    {
        q = p->next;
        free(p);
        p = q;
    }
    free(L);
}

void slist_print(slist L) {
    slobj p;
    p = L->head;

    while (p != NULL) 
    {
        printf("%lf", p->v);
        p = p->next;
    }
    printf("-1\n");
}


slobj slist_search(slist L, int x) {
    slobj p;
    p = L->head;
    while (p != NULL && p->v != x) 
    {
        p = p->next;
    }
    return p;
}

void slist_insert(slist L, slobj r) {
    slobj p, q;
    p = L->head;
    q = p;
    while (p != NULL && p->v <= r->v) 
    {
        q = p;
        p = p->next;
    }
    if (p == L->head) 
    {
        L->head = r;
        r->next = p;
    } else 
    {
        q->next = r;
        r->next = p;
    }
}

#pragma endregion slist

#pragma region smatrix

smatrix smatrix_new(int n, int m) {
    smatrix S;
    NEW(S, 1);
    S->n = n;
    S->m = m;
    NEW(S->A, n);
    for(int i = 0;i < n;i ++)
    {
        S->A[i] = slist_new();
    }
    return S;
}

smatrix smatrix_read() {
    smatrix S;
    int n,m,row;
    double x;
    scanf("%d", &n);
    scanf("%d", &m);
    S = smatrix_new(n,m);

    for(int i = 0; i < n; i++) {
        while(1) {
            scanf("%d", &row);
            if (row < 0) break;
            row --;
            scanf("%lf", &x);
            slist_insert_tail(S->A[i], slobj_new(row,x));
            S->A[i]->tail->j = row;
        }
    }
    return S;
}

void smatrix_print(smatrix S) {
    slobj p;
    printf("%d %d\n", S->n, S->m);

    for(int i = 0; i < S->n; i++) {
        p = S->A[i]->head;
        while(p != NULL) {
            printf("%2d ", p->j+1);
            printf("%3.2lf  ", p->v);
            p = p->next;
        }
        printf("-1\n");
    }
}

smatrix smatrix_transpose(smatrix S) {
    slobj p;
    smatrix T;
    T = smatrix_new(S->m,S->n);
    for(int i = 0; i < S->n; i++) {
        p = S->A[i]->head;
        while(p != NULL) {
            slist_insert_tail(T->A[p->j], slobj_new(p->j,p->v));
            T->A[p->j]->tail->j = i;
            p = p->next;
        }
    }
    return T;
}

void smatrix_free(smatrix S) {
    slobj p,q;
    for(int i = 0; i < S->n; i++) {
        p = S->A[i]->head;
        while (p != NULL)  {
            q = p->next;
            free(p);
            p = q;
        }
        free(S->A[i]);
    }
    free(S);
}

double smatrix_access(smatrix S, int i, int j) {
    slobj p;
    p = S->A[i]->head;
    while(1) {
        if(p != NULL) {
            if(p->j == j) {
                return p->v;
            }
            else if (p == NULL) {
                return 0;
            }
            p = p->next;
        }else if (p == NULL) {
            return 0;
        }
    }
}


// sparce_transposeとはこの関数だけが異なる
smatrix smatrix_square(smatrix A) {
    double x = 0;
    double a = 0;
    smatrix C;
    if(A->m != A->n) {
        C = smatrix_new(0,1);
        C->n = 0;
        C->m = 0;
        return C;
    } else {
        C = smatrix_new(A->n,A->m);
    }

    for(int i = 0;i < C->n; i++) {
        for (int j = 0; j < C->m; j++) {
            x=0;
            a=0;
            for (int k = 0; k < C->n; k++) {
                a = smatrix_access(A,i,k) * smatrix_access(A,i,k);
                x += a * a;
            }

            if(x != 0) {
                slobj r;
                r = slobj_new(0,0);
                r->j = j;
                r->v = x;
                slist_insert_tail(C->A[i],r);
            }
        }
    }
    return C;
}

smatrix smatrix_identity(int n) {
    smatrix S;
    S = smatrix_new(n,n);
    for(int i = 0; i < n; i++) {
        slobj r;
        r = slobj_new(i,1);
        slist_insert_tail(S->A[i],r);
    }
    return S;
}

/*
smatrix smatrix_power(smatrix A,int k){
    smatrix X;
    if(k == 0) {
        return smatrix_identity(A->n);
    }
    else if(k == 1) {
        X = smatrix_product(A,smatrix_identity(A->n));
        return X;
    }
    else {
        X = smatrix_product(A,smatrix_power(A,k-1));
    }
    return X;
}
*/
#pragma endregion 

int main(void) {
    smatrix A,B;
    A = smatrix_read();
    B = smatrix_square(A);
    smatrix_print(B);
    smatrix_free(A);
    smatrix_free(B);
    return 0;
}
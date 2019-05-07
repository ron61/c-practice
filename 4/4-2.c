#include <stdio.h>
#include <stdlib.h>
#define NEW(p,n) {p = malloc((n)*sizeof(p[0])); if ((p)==NULL) {printf("not enough memory¥n"); exit(1);};}

typedef struct slobj_ 
{
    struct slobj_* next; // 後の要素へのポインタ
    int j; // j列目　
    double v; // (i,j)要素
}* slobj;

typedef struct 
{
    slobj head; // 先頭要素のポインタ
    slobj tail; // 末尾要素のポインタ
}* slist;

typedef struct 
{
    int n,m;
    slist* A;
}* smatrix;



slobj slobj_new(int x)
{
    slobj p;
    NEW(p,1);
    p->v = x;
    p->next = NULL;
    return p;
}

slist slist_new(void)
{
    slist L;
    NEW(L,1);
    L->head = NULL;
    return L;
}

void slist_insert_head(slist L, slobj p) 
{ 
    p->next = L->head; 
    L->head = p; 
}

void slist_insert_tail(slist L, slobj r)
{
    slobj p;
    NEW(p,1);
    L->tail->next = r;
    p = L->tail;
    L->tail = r;
    if(L->head == NULL)
    {
        L->head = r;
    }
}

void slist_free(slist L)
{
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

void slist_print(slist L)
{
    slobj p;
    p = L->head;

    while (p != NULL) 
    {
        printf("%d ", p->v);
        p = p->next;
    }
    printf("-1¥n");
}


slobj slist_search(slist L, int x)
{
    slobj p;
    p = L->head;
    while (p != NULL && p->v != x) 
    {
        p = p->next;
    }
    return p;
}

void slist_insert(slist L, slobj r)
{
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

slist slist_read_and_sort(FILE *in)
{
    slist L;
    int x;
    L = slist_new();
    while (1) 
    {
        fscanf(in, "%d", &x);
        if (x < 0) break;
        slist_insert(L, slobj_new(x));
    }
    return L;
}

slist slist_join(slist L1, slist L2)
{
    slist L3;
    int v1, v2;
    slobj p1, p2, p3;
    L3 = slist_new();
    p1 = L1->head; 
    p2 = L2->head;
    while (p1 != NULL && p2 != NULL) 
    {
        v1 = p1->v;
        v2 = p2->v;
        if (v1 < v2) 
        {
            p1 = p1->next;
        } else if (v1 > v2) 
        {
            p2 = p2->next;
        } else 
        {
            p3 = slobj_new(v1);
            slist_insert(L3, p3);
            p1 = p1->next;
            p2 = p2->next;
        }         
    }
    return L3;
}

smatrix smatrix_new(int n, int m)
{
    int i;
    smatrix S;
    NEW(S, n)
    for(i = 0;i < n;i ++)
    {
        NEW(S->A[i], m)
        S->A[i] = slist_new();
    }
    return S;
}

smatrix smatrix_read()
{
    smatrix S;
    int n,m,row;
    double x;
    S = smatrix_new(n,m);

    scanf("%d", &n);
    scanf("%d", &m);

    for(int i = 0; i < n; i++)
    {
        while(1)
        {
            scanf("%d", &row);
            scanf("%lf", &x);
            if (row < 0) break;
            slist_insert_tail(S->A[i], slobj_new(x));
            S->A[i]->tail->j = row;
        }
    }
    return S;
}

void smatrix_print(smatrix S)
{
    slobj p;
    printf("%d %d\n", S->m, S->n);

    for(int i = 0; i < S->n; i++)
    {
        p = S->A[i]->head;
        while(p != NULL)
        {
            printf("%d ", p->j);
            printf("%lf ", p->v);
            p = p->next;
        }
        printf("-1¥n");
    }
}

smatrix smatrix_transpose(smatrix S)
{
    slobj p;
    smatrix T;
    T = smatrix_new(S->m,S->n);
    for(int i = 0; i < S->n; i++)
    {
        p = S->A[i]->head;
        while(p != NULL)
        {
            slist_insert_tail(T->A[p->j], slobj_new(p->v));
            T->A[p->j]->tail->j = i;
            p = p->next;
        }
    }
    return T;
}

void free_smatrix(smatrix S)
{
    slobj p,q;
    for(int i = 0; i < S->n; i++)
    {
        p = S->A[i]->head;
        while (p != NULL) 
        {
            q = p->next;
            free(p);
            p = q;
        }
        free(S->A[i]);
    }
    free(S);
}

int main(void)
{
    smatrix S,T;
    int n,m;
    scanf("%d", &n);
    scanf("%d", &m);
    S = smatrix_read();
    T = smatrix_new(m,n);
    T = smatrix_transpose(S);
    smatrix_print(T);
    smatrix_free(S);
    smatrix_free(T);
    return 0;
}
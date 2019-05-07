#include <stdio.h>
#include <stdlib.h>
#define NEW(p,n) {p = malloc((n)*sizeof(p[0])); if ((p)==NULL) {printf("not enough memory¥n"); exit(1);};}

typedef char* String;

typedef struct slobj_ 
{
    String str; // 文字列
    struct slobj_* next; // 後の要素へのポインタ
}* slobj;

typedef struct 
{
    slobj head; // 先頭要素のポインタ
    slobj tail; // 末尾要素のポインタ
}* slist;

typedef struct
{
    int n;
    slist* A;
}* str_list;


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

str_list str_list_new(int n)
{
    str_list S;
    NEW(S, 1);
    S->n = n;
    NEW(S->A, n);
    for(int i = 0;i < n;i ++)
    {
        S->A[i] = slist_new();
    }
    return S;
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

String string_input(void)
{
    int c,i,len;
    char buf[1000];
    String str;
    scanf("%s",buf);

    len = string_len(buf);

    NEW(str,len+1);
    for (int i = 0; i < len; i++)
    {
        str[i] = buf[i];
    }
    str[len] = 0;
    return str;
}

str_list str_list_read()
{
    str_list S;
    int n;
    String str;
    scanf("%d", &n);
    S = str_list_new(n);

    for(int i = 0; i < n; i++)
    {
        
        S->A[i] = string_input();
        S->A[i]->tail->j = row;
        
    }
    return S;
}

int main()
{
    str_list S;
    S = str_list_read();
    

}
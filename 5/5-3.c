#include <stdio.h>
#include <stdlib.h>
#define NEW(p,n) {p = malloc((n)*sizeof(p[0])); if ((p)==NULL) {printf("not enough memory¥n"); exit(1);};}

typedef char* String;

typedef struct slobj_ 
{
    struct slobj_* next; // 後の要素へのポインタ
    int j; // j列目
    String str; // 文字列
}* slobj;

typedef struct 
{
    int n; // 行数
    slobj head; // 先頭要素のポインタ
    slobj tail; // 末尾要素のポインタ
}* slist;

slobj slobj_new(String str)
{
    slobj p;
    NEW(p,1);
    p->str = str;
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

int string_len(String str)
{
    int len = 0;
    while (str[len] != 0)
    {
        len ++;
    }
    return len;
}

int string_compare(String p,String q)
{
    int i = 0;
    while(1)
    {
        if(q[i] == 0 && p[i] == 0)
        {
            return 0;
        }
        else if(p[i] < q[i])
        {
            return -1;
        }
        else if(p[i] > q[i])
        {
            return 1;
        }
        else 
        {
            
        }
        i ++;
    }
}

void slist_insert(slist L, slobj r)
{
    slobj p, q;
    p = L->head;
    q = p;
    while (p != NULL && string_compare(p->str,r->str) == -1) 
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


void slist_insert_tail(slist L, slobj r)
{
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

String string_read(void)
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

slist slist_read_and_sort(void)
{
    slist L;
    int n;
    scanf("%d",&n);
    L = slist_new();
    String str;
    slobj r;

    for (int i = 0; i < n; i++)
    {
        String str;
        slobj r;
        str = string_read();
        /*
        int i = 0;
        while(str[i] != 0)
        {
            printf("%s", &str[i]);
            i ++;
        }
        */
        r = slobj_new(str);
        slist_insert(L, r);
    }
    return L;
}

void slist_print(slist L) {
    slobj p;
    p = L->head;

    while (p != NULL) 
    {
        int i = 0;
        while(p->str[i] != 0)
        {
            printf("%c", p->str[i]);
            // printf("%d",i);
            i ++;
        }
        p = p->next;
        printf("\n");
    }
    printf("\n");
}

int main()
{
    slist L;
    L = slist_read_and_sort();
    slist_print(L);
    slist_free(L);
    return 0;
}

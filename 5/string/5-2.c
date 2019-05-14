#include <stdio.h>
#include <stdlib.h>
#define NEW(p,n) {p = malloc((n)*sizeof(p[0])); if ((p)==NULL) {printf("not enough memory¥n"); exit(1);};}

typedef char* String;


int string_len(String str)
{
    int len = 0;
    while (str[len] != 0)
    {
        len ++;
    }
    return len;
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

int main()
{
    String p,q;
    p = string_input();
    q = string_input();
    printf("%d\n", string_compare(p,q));
    return 0;
}
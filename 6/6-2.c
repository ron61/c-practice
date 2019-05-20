#include <stdio.h>
#include <stdlib.h>
#define NEW(p,n) {p = malloc((n)*sizeof(p[0])); if ((p)==NULL) {printf("not enough memory\n"); exit(1);};}

#pragma region typedef
typedef char* String;

typedef struct slobj_ {
    String key;
    String jpn;
    struct slobj_* next;    
}* slobj;

typedef struct {
  slobj head;
}* slist;

typedef struct {
  int n; 
  int m;
  slist* T;
}* hash;
#pragma endregion

#pragma region String
int string_len(String str)
{
  int len=0;
  while (str[len] != 0) {
    len++;
  }
  return len;
}

int string_compare(String p, String q)
{
  int c1, c2;
  int i = 0;
  while (1) {
    c1 = p[i];  c2 = q[i];
    if (c1 < c2) return -1;
    if (c1 > c2) return  1;
    if (c1 == 0) break;
    i++;
  }
  return 0;
}

String string_input(void)
{
  int i, len;
  char buf[1000];
  String str;
  scanf("%s", buf);

  len = string_len(buf);
  
  NEW(str, len+1);
  for (i=0; i<len; i++) {
    str[i] = buf[i];
  }
  str[len] =0;
  return str;
}
#pragma endregion

#pragma region slobj
slobj slobj_new(String eng, String jpn)
{
  slobj p;
  NEW(p,1);
  p->key = eng;
  p->jpn = jpn;
  p->next = NULL;
  return p;
}

void slobj_free(slobj p)
{
  if (p != NULL) {
    free(p->key);
    free(p->jpn);
    free(p);
  }
}
#pragma endregion

#pragma region slist

slist slist_new(void)
{
  slist L;
  NEW(L,1);
  L->head = NULL;
  return L;
}

slobj slist_search(slist L, String key)
{
    slobj p;
    p = L->head;
    while (p != NULL && string_compare(p->key,key) != 0) 
    {
        p = p->next;
    }
    return p;
}

void slist_free(slist L)
{
  slobj p, q;
  p = L->head;
  while (p != NULL) {
    q = p->next;
    slobj_free(p);
    p = q;
  }
  free(L);
}

void slist_insert_head(slist L, slobj p)
{
  p->next = L->head;
  L->head = p;
}

#pragma endregion

#pragma region hash
int hash_func(hash H, String key)
{
  int h, i;
  h = 0;  i = 0;
  while (key[i] != 0) {
    h = h * 101 + key[i];
    i++;
  }
  return abs(h) % H->m;
}

hash hash_new(int m)
{
  int i;
  hash H;

  NEW(H, 1);
  NEW(H->T, m);
  H->n = 0;
  H->m = m;

  for (i=0; i<m; i++) {
    H->T[i] = slist_new();
  }

  return H;
}

void hash_free(hash H)
{
  int i;
  for (i=0; i<H->m; i++) {
    slist_free(H->T[i]);
  }
  free(H->T);
  free(H);
}

slobj hash_search(hash H, String eng)
{
    slobj p;
    int x;
    x = hash_func(H,eng);
    p = slist_search(H->T[x],eng);

    return p;
}

void hash_insert(hash H, slobj obj)
{
    int x;
    x = hash_func(H,obj->key);
    slist_insert_head(H->T[x],obj);
}
#pragma endregion

int main(void)
{
  hash H;
  slobj obj;
  String eng, jpn;
  int n, i, q;

  H = hash_new(10001);
  scanf(" %d", &n);
  for (i=0; i<n; i++) {
  	eng = string_input();
  	jpn = string_input();
  	hash_insert(H, slobj_new(eng, jpn));
  }
  scanf(" %d", &q);
  for (i=0; i<q; i++) {
  	eng = string_input();
    obj = hash_search(H, eng);
    if (obj != NULL) {
      printf("%s %s\n", obj->key, obj->jpn);
    } else {
      printf("NO\n");
    }
  }
  hash_free(H);
  return 0;

}

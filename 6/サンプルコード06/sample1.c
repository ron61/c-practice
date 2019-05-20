/////////////////////////////////////////////////////////////////////////////
// リストを用いた実現
/////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#define NEW(p,n) {p = malloc((n)*sizeof(p[0])); if ((p)==NULL) {printf("not enough memory\n"); exit(1);};}

typedef struct slobj_ {
  struct slobj_ *next;     // 後の要素へのポインタ
  int key;                 // キー
  double value;            // 付属データ
}* slobj;

typedef struct {
  slobj head;            // 先頭要素のポインタ
}* slist;

slobj slobj_new(int key, double value)
{
  slobj p;
  NEW(p,1);
  p->key = key;
  p->value = value;
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

void slist_free(slist L)
{
  slobj p, q;
  p = L->head;
  while (p != NULL) {
    q = p->next;
    free(p);
    p = q;
  }
  free(L);
}

slobj slist_search(slist L, int k)
{
  slobj p;
  p = L->head;
  while (p != NULL && p->key != k) {
    p = p->next;
  }
  return p;
}

int main()
{
  slist L;
  slobj obj;
  int n, i, k, q;
  double v;
  L = slist_new();
  scanf(" %d", &n);
  for (i=0; i<n; i++) {
  	scanf(" %d %lf", &k, &v);
  	slist_insert_head(L, slobj_new(k, v));
  }
  scanf(" %d", &q);
  for (i=0; i<q; i++) {
    scanf(" %d", &k);
    obj = slist_search(L, k);
    if (obj != NULL) {
      printf("%d %lf\n", obj->key, obj->value);
    } else {
      printf("NO\n");
    }
  }
  slist_free(L);
  return 0;
}

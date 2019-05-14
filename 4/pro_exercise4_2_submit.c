#include<stdio.h>
#include<stdlib.h>

#define NEW(p,n) {p = malloc((n)*sizeof(p[0]));if ((p)==NULL){printf("not enough memory\n");exit(1);};}

typedef struct slobj_ {
    struct slobj_ *next;
    int j;
    double v;
}* slobj;

typedef struct{
    slobj head;
    slobj tail;
}* slist;

typedef slist* row_vector_sparse;

typedef struct{
    int n,m;
    row_vector_sparse A;
}* smatrix;

slobj slobj_new(int i,double x){
    slobj p;
    NEW(p,1);
    p->j=i;
    p->v=x;
    p->next=NULL;
    return p;
}

slist slist_new(void){
    slist L;
    NEW(L,1);
    L->head = NULL;
    L->tail = NULL;
    return L;
}

void slist_print(slist L){
    slobj p;
    p = L->head;
    while(p!=NULL){
        printf("%d %lf ",p->j,p->v);
        p = p->next;
    }
    printf("-1\n");
}

row_vector_sparse create_row_vector_sparse(int m){
  int i;
  row_vector_sparse A;
  NEW(A, m);
  for (i=0; i<m; i++) A[i] = slist_new(); 
  return A;
}

smatrix create_smatrix(int n,int m){
    int i;
    smatrix S;
    NEW(S,1);
    S->n = n;
    S->m = m;
    S->A = create_row_vector_sparse(n);
    return S;
}

void slist_insert(slist L,slobj r){
    slobj p,q;
    p = L->head;
    q = p;
    while(p != NULL && p->j <= r->j){
        q = p;
        p = p->next;
    }
    if (p == L->head){
        L->head = r;
        r->next =p;
    }else{
        q->next = r;
        r->next = p;
    }
}

void smatrix_insert(smatrix S,int i,int j,double x){
    slobj p;
    p = slobj_new(j,x);
    slist_insert(S->A[i-1],p);
}

void slist_insert_head(slist L,slobj p){
    p->next = L->head;
    L->head = p;
}

void slist_insert_tail(slist L,slobj p){
    if(L->head == NULL){
        L->head = p;
        L->tail = p;
    }else{
        L->tail->next = p;
        L->tail = p;
    }
}

slobj slist_search(slist L,int x){
    slobj p;
    p = L->head;
    while(p != NULL && p->j != x){
        p = p->next;
    }
    return p;
}

double smatrix_access(smatrix S,int i,int j){
    slobj p;
    p = slist_search(S->A[i-1],j);
    if(p == NULL){
        return 0;
    }else{
        return p->v;
    }
}

smatrix transpose_smatrix(smatrix S){
    smatrix U;
    slobj p,q;
    int i;
    U = create_smatrix(S->m,S->n);
    for(i=0;i<S->n;i++){
        p=S->A[i]->head;
        while(p!=NULL){
            q=slobj_new(i+1,p->v);
            slist_insert_tail(U->A[p->j-1],q);
            p=p->next;
        }
    }
    return U;
}

smatrix multiply_smatrix(smatrix S,smatrix T){
    int k,l;
    double x,y;
    slobj p,q;
    smatrix U;
    if(S->m==T->n){
        U = create_smatrix(S->n,T->m);
        for(k=0;k < S->n;k++){
            for(l=1;l <= T->m;l++){
                y = 0;
                p = S->A[k]->head;
                while(p != NULL){
                    x = smatrix_access(T,p->j,l);
                    y += x*(p->v);
                    p = p->next;
                }
                if(y != 0){
                    q = slobj_new(l,y);
                    slist_insert_tail(U->A[k],q);
                }
            }
        }
    }else{
        U = NULL;
    }
    return U;
}

smatrix read_matrix(){
    int c,i,j,n,m;
    double x;
    slobj p;
    smatrix S;
    scanf("%d %d",&n,&m);
    S = create_smatrix(n,m);
    for(i=0;i<n;i++){
        while(1){  
        scanf("%d",&j);
        if(j==-1){
            break;
        }
        scanf("%lf",&x);
        p = slobj_new(j,x);
        slist_insert_tail( S->A[i] ,p);
        }
    }
    return S;
}

void slist_free(slist L){
    slobj p,q;
    p = L->head;
    while(p!=NULL){
        q = p->next;
        free(p);
        p = q;
    }
    
    free(L);
}

void smatrix_free(smatrix S){
    int i;
    if(S!=NULL){
        for(i=0;i < S->n;i++){
            slist_free(S->A[i]);
        }
    }
    free(S);
}

void smatrix_print(smatrix S){
    int i;
    if(S != NULL){
        printf("%d %d\n",S->n,S->m);
        for(i=0;i < S->n;i++){
            slist_print(S->A[i]);
        }
    }else{
        printf("0 0\n");//改行ではじかれる?
    }
}

int main(){
    smatrix S,U;
    S = read_matrix();
    //U = create_smatrix(S->n,T->m);
    
    U = transpose_smatrix(S);

    smatrix_print(U);

    smatrix_free(S);
    smatrix_free(U);
    return 0;
}

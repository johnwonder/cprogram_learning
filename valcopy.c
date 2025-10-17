#include <stdio.h>

typedef struct lua_TValue {

    int tt_;
} TValue;

typedef struct Proto {

   TValue k[1];
} Proto;
static int copy(Proto *p);
static int addk (Proto *p,TValue *key, TValue *v);
int main(int argc,char *args[]){

   
    Proto p;
    
    copy(&p);

    printf("%d",p.k[0].tt_);

    fwrite("hello", sizeof(char),5, stdout);
}

static int copy(Proto *p){

    TValue o;
    o.tt_ = 2;

    addk(p,&o,&o);
}
static int addk (Proto *p,TValue *key, TValue *v){
      

    p->k[0] = *key;
}

#include <stdio.h>

static void externfunc();


int main(){

    externfunc();

    printf("%d",__LINE__) ;//10

    printf("%d",__LINE__) ;//12
}

void externfunc(){

    printf ("hello world\n");
}
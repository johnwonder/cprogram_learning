#include <stdio.h>

    typedef long Align;    

    union header {         
        /* for alignment to long boundary */ 
        /* block header */ 
        struct { 
        union header *ptr; /* next block if on free list */ 
        long long size;
        char c;
        /* size of this block */ 
        } s; 
        Align x;           
    }; 
/* force alignment of blocks */
typedef union header Header;
    static Header base; 
int main(){


        Header *p =&base;
        printf("p size %zu\n",sizeof(p));
        printf("unsigned size %zu\n",sizeof(unsigned));
         printf("long size  %zu\n",sizeof(long));
                printf("long long size  %zu\n",sizeof(long long));
        printf("Header size is %zu\n",sizeof(Header)); //16 字节对齐了
        printf("p pointer address %p\n",p);
        printf("p+1 pointer address %p\n",p+1);
}
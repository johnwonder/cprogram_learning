#include <stdio.h>
#include <string.h>

int main(){
 
    struct s
    {
        int j;
        /* data */
    } *s;

    struct sdshdr5 {
        unsigned char flags; /* 3 lsb of type, and 5 msb of string length */
        char buf[];
    };
    printf("sizeof(sdshdr5) = %zu\n", sizeof(struct sdshdr5)); //8
   
    
    printf("sizeof(s) = %zu\n",sizeof(s)); //8
    printf("sizeof(*s) = %zu\n",sizeof(*s)); //4


    struct key { 
        char *word; 
        int count; 
        } keytab[] = { 
        "auto", 0, 
        "break", 0, 
        "case", 0, 
        "char", 0, 
        "const", 0, 
        "continue", 0, 
        "default", 0, 
        /* ... */ 
        "unsigned", 0, 
        "void", 0, 
        "volatile", 0, 
        "while", 0 
        };
        printf("keytab size = %zu\n",sizeof keytab );
        printf("struct key size = %zu\n",sizeof(struct key));
        printf("%d\n",sizeof keytab / sizeof(struct key));
         printf("sizeof(keytab[0]) = %d\n", sizeof(keytab[0]));

        printf(" keytab[0]  word first elemet address = %p\n", keytab[0].word);
        printf(" keytab[0]  word second elemet address = %p\n", keytab[0].word+1);
        printf(" keytab[0]  word first elemet   = %s\n", keytab[0].word);
         printf(" keytab[0]  word address = %p\n", &keytab[0].word);
           printf(" keytab[0]  word = %p\n", &keytab[0].count);
        printf("sizeof keytab / sizeof(keytab[0]) = %d\n", sizeof keytab / sizeof(keytab[0]));


        struct t { 
         
            struct ss *p;   /* p points to an s */ 
         }; 
        struct ss { 
        
            struct t *q;   /* q points to a t */ 
        };
       
}
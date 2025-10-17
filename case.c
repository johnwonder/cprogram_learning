#include <stdio.h>

int main(int argc,char *args[]){

    int i = 1;
    switch(i){


        case 0:
            break;
        case 1: {
            int j = 2;
            switch (j) {
                case 2: goto read_save;
                default: break;
            }
            read_save:
                printf("read_save\n");
            only_save:
                printf("only_save\n");
            /* go through */
            no_save:  printf("no_save\n"); break;
        }
        default:
            break;
             
        

    }
}
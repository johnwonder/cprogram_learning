#include <stdio.h>
#include <string.h>
    
#define LEN 1024 *1024 *1024
char s[LEN];
int main(){
 


    for (size_t i = 0; i < LEN -1; i++)
    {
        /* code */
        s[i] = 'a';
    }

        s[LEN - 100] = '\r';
        s[LEN-1] = '\0';

      char *newline  = strchr((char*)s,'\r');

    printf("newline: %s",newline);

    return 0;
}
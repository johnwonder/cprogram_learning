#include <stdio.h>

int main(){

   
    const char* pointer = "hello world";

    printf("pointer string = %s\n",pointer); //输出整个字符串
    printf("pointer first char = %c\n",*pointer);//输出第一个字符h
    
    printf("pointer = %p\n",pointer);
    printf("pointer+1 = %p\n",pointer+1);
    printf("pointer[0] = %p\n",&pointer[0]);

    printf("&pointer = %p\n",&pointer);

    printf("&pointer+1 = %p\n",&pointer + 1);


    const char cp[12] = "hello world";
    printf("cp convert to string = %s\n",cp);
    printf("cp[0] = %c\n",*cp);
    printf("cp = %p\n",cp); //00000083325FF87C
    printf("&cp = %p\n",&cp); //00000083325FF87C

    printf("&cp+1 = %p\n",&cp + 1); //00000083325FF888

    printf("cp[1] = %c\n",*(cp+1));
    printf("cp+1 = %p\n",cp+1);//00000083325FF87D
}
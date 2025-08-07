#include <string.h>
#include <stdio.h>

int main(){


    char* charp[] = { "ss","ccccc" };

    char** charp1 = charp;

    printf("char** %s",charp1[1]);

    char* str = "1\\n";

    printf("str len = %zu\n",strlen(str)); //输出3
    printf("str value = %s\n",str);

    char* str1 = "1\n"; //\n 已经是一个转义序列

    printf("str len = %zu\n",strlen(str1)); //输出2
    printf("str value = %s\n",str1);//1

    char* str2 = "Hello, \115!";

    printf("str2 value = %s\n",str2);//1

    signed char c = -1;

     printf("c value = %c\n",c);//1


}
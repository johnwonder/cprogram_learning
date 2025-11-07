#include <stdio.h>

// #define USE_SYSTEM_SQLITE

int main(){

#if USE_SYSTEM_SQLITE+0!=1
    printf("USE_SYSTEM_SQLITE");
#else
   printf("%d\n",USE_SYSTEM_SQLITE);
#endif
      unsigned int num1 = 8; //1000
    unsigned int num2 = 12;
    //unsigned int num3 = 36952;
    unsigned int result = num1 ^ num2;
    printf("The result is: %u\n", result);
}
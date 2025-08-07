#include <stdio.h>

#define lua_assert(c)		(i++)

#define check_exp(c,e)		(lua_assert(c), (e))
int main(){

    int i = 0;
    int val = check_exp(0, i + 5);
    int val1 = (lua_assert(i == 0), (i+15));
    //展开来等同于
    // int val = ((i++), (i + 5));
    // int val1 = ((i++), (i+15));
    printf("%d\n",val); //6 
   printf("%d",val1); //17
}
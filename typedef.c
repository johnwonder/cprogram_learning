#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef int (*array_ptr)[100];

#define lua_assert(c)		(c)
#define luai_apicheck(e)	{ printf("%s",e); }
#define api_check(e,msg)	luai_apicheck((e) && msg)
int main(){

    //array_ptr a = {100,10};

   array_ptr a = malloc(sizeof(int[100]));
    //assert(5 > 10 && "x should be greater than 10"); 
    api_check(1 > 0,"failed");
   
   
    
    //*a[0] = 1;
    //printf("%d",*a[0]);
   int arr[100] = {5,2,3,4,5,};

   array_ptr b = &arr;
   printf("%d",*b[0]);

}
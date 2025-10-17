#include <stdio.h>

char* returnCharS();
char* returnCharArr();
int main(int argc,char *args[]){

    char* r = returnCharS();

    printf("%s",r);

      //char* arr = returnCharArr();
      //printf("%s",arr);

}

char* returnCharS(){

    char* s = "hello";
    return s;
}

/*直接编译不通过*/
// char* returnCharArr(){

//     char s[] = {'s','s'};

//     return s;
// }
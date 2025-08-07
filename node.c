#include <stdio.h>


typedef struct Node {
   int a;
} Node;

void test1(char *a);

int main(int argc,char *args[]){


   Node nodes[2] ={ {1} ,{2}};

   Node *np = nodes;

   int arr1[] = {1,2,3,5};
   int arr2[] = {1,2,4};
   int arr3[] = {1,2,3};
   int arr4[] = {1,2,3};
   int arr5[] = {1,2,3};
   int *i[5] = { arr1,arr2,arr3,arr4,arr5};

   int *j[5][2] = { {arr1,arr2},{arr1,arr1},{arr1,arr1},{arr1,arr1},{arr1,arr1}};

   printf("%d\n",i[0][3]);
   printf("%d\n",j[0][1][2]);//输出4


   char str[] = "Hello";

   char *strp = str;

   *(strp +1) = 'a';

   char *strp1 = &str[0];
   printf("%s",strp1);
 
  test1(str);

   printf("%d",(int)(np - (np + 1) ));
}


void test1(char *a){

   char *g = a;
   *(g+1) = 'a';
   printf("%s",a+1);
}
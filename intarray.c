#include <stdio.h>

int main(void){


   int i = 1801/1000;

   printf("1001/1000:%d",i);

   int zippo[4][2]= { {2,4} , {6,8} , {1,3}, {5,7}  };

    printf(" zippo = %x, zippo+1 = %x \n", zippo,zippo+1);
      printf(" *zippo = %x, *zippo+1 = %x \n", *zippo,*zippo+1);

    //数组的起始地址
    printf("&zippo = %x\n",&zippo); // 925ffc00

    //因为是&zippo是数组，被看成int(*)[2]，
    //所以sizeof(zippo)是32，也就是8*sizeof(int)， 
    printf("&zippo+1 = %x\n",&zippo+1); // 925ffc20

    //输出32,代表数组占32个字节
    printf("sizeof(zippo) = %zu\n",sizeof(zippo));

    //输出8 ，代表指针占 8个字节
    printf("sizeof(&zippo) = %zu\n",sizeof(&zippo));
}
#include <stdio.h>

int main(){


        /*
         计算 _n 距离下一个 sizeof(long) 对齐地址的偏移量（即需要填充的字节数）。

         例如：若 sizeof(long)=8（64位系统），_n=13，则结果为 8 - (13 & 7) = 8 - 5 = 3，
         表示需要填充 3 字节才能对齐到 8 的倍数（即 16）。
        
        */
        int _n = 4;
        _n +=  sizeof(long)-(_n&(sizeof(long)-1));

        //
        printf("%d\n",_n);


        int i = 1<<0;

        printf("%d\n",i);

}
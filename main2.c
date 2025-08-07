#include <stdio.h>

typedef struct redisObject {
    
    void* ptr;

    
} robj;

void encode(robj* o){

    long long l = 100L;
    o->ptr = (void*) l;
}
int main(){




    robj obj;
    //obj.ptr = 100L;

    encode(&obj);
    printf("%p\n",obj.ptr); //0000000000000064 16进制
   for(int i = 0;i < 10;i++){
    
        //printf("%ld\n", *(long long*)obj.ptr); 操作直接没反应
        printf("%ld\n", (long long)obj.ptr);
   }
 
  
    int a;




    printf("heel\n");

    printf("%d \" \n", a);
    //\n 只代表一个字符。类似于\n 的转义字符序列为表示无法输入的字符或不可见
    //字符提供了一种通用的可扩充的机制。除此之外，
    //C 语言提供的转义字符序列还包括：
    //\t 表示制表符；
    //\b 表示回退符；
    //\"表示双引号；
    //\\表示反斜杠符本身。
    printf("\" \t \b \\ \n"); //\c

    int  fahr,celsius;
    int lower,upper,step;

    lower = 0;
    upper = 300;
    step =20;

    //华氏温度转为摄氏温度
    fahr = lower;
    while (fahr <= upper)
    {
        //摄氏度
        celsius = 5 * (fahr -32) /9;
        //右对齐
        printf("%3d\t%6d\n",fahr,celsius);
        fahr = fahr + step;
    }
    
    //float 类型通常是 32 位，它至少有 6 位有效数字，取值范围一般在 10-38～1038之间。
    //char 字符 一个字节
    // short 短整型
    // long 长整型
    // double 双精度浮点型

}
#include <stdio.h>

void foo(void){
    int a;
    printf("%d\n",a);
}

void bar(void){
    int a = 42;
}

#define S_S 1
void f(void){
    static int a = 3;
    //c的编译器会初始化静态变量为0，因为这只是在启动程序时的动作
    static int b;

    int c;
    ++a;++b;++c;
    printf("a=%d\n",a);
    printf("b=%d\n",b);
    printf("c=%d\n",c);
}
int main(){

    int a = S_S;
    //如果你使用一般的编译，会输出42，因为我们的编译器优化了函数的调用栈（重用了之前的栈），为的是更快，这没有什么副作用。
    //反正你不初始化，他就是随机值，既然是随机值，什么都无所谓
    bar();
    foo();
    //如果你的编译打开了代码优化的开关，-O，这意味着，foo()函数的代码会被优化成main()里的一个inline函数，也就是说没有函数调用，就像宏定义一样。
    //于是你会看到一个随机的垃圾数。
    //https://gcc.gnu.org/onlinedocs/gcc-13.3.0/gcc/Optimize-Options.html

    // f();
    // f();
    // f();


    //int a = 42;
    //printf("%d\n",a);

    //只有d，f，g输出42，而e和h的行为则是未定义的
    //关于这种未定义的东西是因为Sequence Points的影响（Sequence Points是一种规则，
    //也就是程序执行的序列点，在两点之间的表达式只能对变量有一次修改）
    int d =41; d++; printf("d: %d\n",d);
     int e =41; e++ & printf("e: %d\n",e);
     int f =41; f++ && printf("f: %d\n",f);
    int g =41; if(g++ < 42) printf("g: %d\n",g);
    int h =41; h= h++; printf("h: %d\n",h);


    struct X
    {
        int a;
        char b;
        int c;
        /* data */
    };

    printf("sizeof(struct X):%d\n",sizeof(struct X));

    struct Y
    {
        int a;
        char b;
        int c;
        char d;
        /* data */
    };
     printf("sizeof(struct Y):%d\n",sizeof(struct Y));
    //但是，你知道为什么要字节对齐吗？还是因为性能。因为这些东西都在内存里，如果不对齐的话，
    //我们的编译器就要向内存一个字节一个字节的取，这样一来，struct X，就需要取9次，太浪费性能了，
    //而如果我一次取4个字节，那么我三次就搞定了。所以，这是为了性能的原因。
    //但是，为什么struct Y不向12 对齐，却要向16对齐，
    //因为char d; 被加在了最后，当编译器计算一个结构体的尺寸时，是边计算，边对齐的。
    //也就是说，编译器先看到了int，很好，4字节，然后是 char，一个字节，而后面的int又不能填上还剩的3个字节，不爽，把char b对齐成4，于是计算到d时，就是13 个字节，于是就是16啦。但是如果换一下d和c的声明位置，就是12了。
    
    //再提一下，上述程序的printf中的%d并不好，因为，在64位下，sizeof的size_t是unsigned long，而32位下是 unsigned int，所以，C99引入了一个专门给size_t用的%zu。
    //这点需要注意。在64位平台下，C/C++ 的编译需要注意很多事。
}
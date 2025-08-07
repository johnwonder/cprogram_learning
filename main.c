#include <stdio.h>


void func(int b[]){
    //warning: 'sizeof' on array function parameter 'b' will return size of 'int *' [-Wsizeof-array-argument]
    printf("sizeof(b) = %zu\n",sizeof(b));
}
int main1(void){

    int a[5];


    printf("%x\n",a); //5ffe80
    printf("%x\n",a+1); //5ffe84

    //https://coolshell.cn/articles/5761.html
    //如果是 int *a，那么没有问题，因为a是指针，
    //所以 &a 是指针的地址，a 和 &a不一样。
    //但是这是数组啊a[]，所以&a其实是被编译成了 &a[0]。
    // printf("%x\n",&a); //5ffe80

    //因为是&a是数组，被看成int(*)[5]，
    //所以sizeof(a)是20，也就是5*sizeof(int)，也就是bfe2e114
    printf("%x\n",&a+1); //5ffe94

    //a+1 就是数组的第二个元素地址

    //输出20,代表数组占20个字节
    printf("%zu\n",sizeof(a));

    //输出8 ，代表指针占 8个字节
    printf("sizeof(&a)： %zu\n",sizeof(&a));

    //https://baijiahao.baidu.com/s?id=1626589052981505887&wfr=spider&for=pc
    int b;
    //b是int值，4代表int占4个字节
    printf("b: %zu\n",sizeof(b)); //4
    //sizeof用来求一个对象(类型，变量，……)所占的内存大小(以字节为单位)
    //&b是取b的地址 ,地址占8个字节
    printf("&b %zu\n",sizeof(&b)); //8

    int *c;
    //c是指针，8代表指针占8个字节
    printf("c: %zu\n",sizeof(c)); //8
    //*c是int值，代表int占4个字节
    printf("*c %zu\n",sizeof(*c)); //4

    ////当数组名为一个函数参数，当作指针来看
    int d[500];
    func(d);

    //输出8
    printf("sizeof(char*) ：%zu",sizeof(char*));

    // int a;

    // printf("%d\n",a);

    // printf("hello world\n");
    
}


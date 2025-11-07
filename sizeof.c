#include <stdio.h>
#include <stdlib.h>

int main() {


    int a =1;
    printf("int : %zu bytes\n", sizeof(a = 3)); //20
    printf("int : %zu bytes\n", sizeof(a)); //20
    printf("a : %d \n", a); //1

    // 在栈上静态分配数组
    int stackArray[5];
    // 获取栈上数组的大小
    size_t stackArraySize = sizeof(stackArray);

    // 在全局作用域静态分配数组
    static int globalArray[3];
    // 获取全局数组的大小
    size_t globalArraySize = sizeof(globalArray);

    printf("stack: %zu bytes\n", stackArraySize); //20
    printf("gloal: %zu bytes\n", globalArraySize);//12


    // 使用malloc动态分配数组
    int *dynamicArray = (int *)malloc(5 * sizeof(int));
    if (dynamicArray == NULL) {
        perror("malloc");
        return 1;
    }

    // sizeof操作的是指针dynamicArray，而非数组本身
    size_t pointerSize = sizeof(dynamicArray);

    printf("pointer size: %zu bytes\n", pointerSize);

    // 释放动态分配的内存
    free(dynamicArray);
    return 0;
}
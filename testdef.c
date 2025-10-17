#include <stdio.h>
#include "constants.def"  // 直接导入 .def 文件

typedef enum opcode_t
{
// #define OPDEF(c,s,pop,push,args,type,l,s1,s2,ctrl) c,
// #include "opcode.def"
// #undef OPDEF
  CEE_COUNT,        /* number of instructions and macros pre-defined */
} OPCODE;

int main() {
    printf("MAX_SIZE: %d\n", MAX_SIZE);
    printf("PI: %.5f\n", PI);
    printf("3 + 5 = %d\n", ADD(3, 5));


    enum opcode_t c = CEE_COUNT;  // 声明枚举变量并赋值
    
    if (c == CEE_COUNT) {
        printf("CEE_NOP\n");  // 输出：颜色是绿色
    }

    int arr[] = {10, 20, 30};
    int* ptr = arr;

    // 先获取 *ptr（10），再将 ptr 指向 arr[1]
    int val = *ptr++; 

    printf("%d",val); //10

    printf("%d",*ptr);//20
    return 0;
}
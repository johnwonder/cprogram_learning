#include <stdio.h>

int main() {
    #ifdef __CHAR_SIGNED__
        printf("char is signed\n");
    #else
        printf("char is unsigned\n");
    #endif
    //return 0;

    signed char sc = -1; // 显式声明一个带符号的字符变量，并初始化为-1

    // 打印变量的值和类型信息
    printf("The value of signed char sc is: %d\n", sc);
    printf("The size of signed char is: %zu bytes\n", sizeof(signed char));

    // 检查sc的符号性（此步骤其实多余，因为我们已经显式声明了signed char）
    if (sc < 0) {
        printf("signed char sc is signed (it can hold negative values).\n");
    } else {
        printf("signed char sc is not signed (this should not happen in this example).\n");
    }


    char neterr[256] = "neterrssss";

    printf("%s",neterr);
}

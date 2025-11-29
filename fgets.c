#include <stdio.h>
#include <string.h>

int main() {
    char buf[2]; // 缓冲区，每次调用 fgets 都从 buf[0] 开始写

    // 第一次调用：读取用户输入，写入 buf[0]~buf[n]
    printf("first:");
    fgets(buf, sizeof(buf), stdin);

    printf("strpbrk %s\n",strpbrk(buf, "\n"));
    buf[strcspn(buf, "\n")] = '\0'; // 去掉换行符
    printf("first read buf:%s\n", buf); // 比如输入 "hello"，buf 是 "hello"

    // 第二次调用：从 buf[0] 开始覆盖，上一次的 "hello" 会被新内容替换
    printf("second:");
    fgets(buf, sizeof(buf), stdin);
    buf[strcspn(buf, "\n")] = '\0';
    printf("second buf:%s\n", buf); // 比如输入 "world"，buf 变成 "world"（覆盖了之前的 "hello"）

    return 0;
}
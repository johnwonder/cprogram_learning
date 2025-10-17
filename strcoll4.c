#include <stdio.h>

#include <string.h>
#include <locale.h>

void print_bytes(const char* str, const char* name) {
    printf("%s 的字节（十六进制）：", name);
    for (int i = 0; i < strlen(str); i++) {
        printf("0x%02X ", (unsigned char)str[i]);
    }
    printf("\n");
}
int main(){


     const char* beijing = "橙子";
    const char* shanghai = "苹果";
 
 setlocale(LC_COLLATE, "zh_CN.UTF-8");
    //setlocale(LC_COLLATE, "Chinese_People's Republic of China.936");
    print_bytes(beijing, "橙子");
    print_bytes(shanghai, "苹果");
 
    //GBK
     printf("strcoll(橙子, 苹果) = %d  ", strcoll("橙子", "苹果")); //此时返回1
     printf("strcmp(橙子, 苹果) = %d  ", strcmp("橙子", "苹果")); //此时返回1
}
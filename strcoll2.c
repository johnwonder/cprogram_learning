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

    const char* beijing = "北京";
    const char* shanghai = "上海";
    //setlocale(LC_COLLATE, "Chinese_People's Republic of China.936");
    print_bytes(beijing, "北京");
    print_bytes(shanghai, "上海");
    //GBK
     printf("strcoll(北京, 上海) = %d  ", strcoll("北京", "上海")); //此时返回1
     printf("strcmp(北京, 上海) = %d  ", strcmp("北京", "上海")); //此时返回1
}
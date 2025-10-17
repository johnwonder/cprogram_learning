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


     const char* beijing = "长沙";
    const char* shanghai = "重庆";
    const char* chengdou = "成都";
    setlocale(LC_COLLATE, "");//Chinese_People's Republic of China.936
    print_bytes(beijing, "长沙");
    print_bytes(shanghai, "重庆");
      print_bytes(shanghai, "成都");
    //GBK
     printf("strcoll(长沙, 重庆) = %d  ", strcoll("长沙", "重庆")); //此时返回1
     printf("strcmp(长沙, 重庆) = %d  ", strcmp("长沙", "重庆")); //此时返回1

   
      setlocale(LC_COLLATE, "zh_CN.UTF-8");
     printf("strcoll(长沙, 重庆) = %d  ", strcoll("长沙", "长庆")); // 这时候如果字符串编码是GBK会乱掉
     printf("strcmp(长沙, 重庆) = %d  ", strcmp("长沙", "重庆")); //此时返回1

}
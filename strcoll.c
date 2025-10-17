#include <stdio.h>
#include <string.h>
#include <locale.h>

int main() {
    // 中文字符串（UTF-8 编码）："苹果"（píngguǒ）、"香蕉"（xiāngjiāo）、"橙子"（chéngzi）
    const char *str1 = "苹果";
    const char *str2 = "香蕉";
    const char *str3 = "橙子";

    // 手动定义 UTF-8 字节数组（包含结束符 '\0'）
    const char apple[] = {
        0xE8, 0x8B, 0xB9,  // "苹" 的 UTF-8 编码（3字节）
        0xE6, 0x9E, 0x9C,  // "果" 的 UTF-8 编码（3字节）
        '\0'               // 字符串结束符
    };

    // 用 char* 指向该字节数组
    const char* str = apple;
     printf("字节数组apple为:%s\n",str);

    // 1. 默认 locale（通常是 C 或 POSIX，不支持中文排序）
    printf("=== 默认 locale（C/POSIX） ===\n");
    printf("比较 %s 和 %s: %d\n", str, str2, strcoll(str, str2));
    printf("比较 %s 和 %s: %d\n", str2, str3, strcoll(str2, str3));
    printf("比较 %s 和 %s: %d\n", str1, str3, strcoll(str1, str3));
    // 结果说明：按字节值乱排，与拼音无关


    // 2. 设置中文 locale（需系统支持，如 zh_CN.UTF-8）
    if (setlocale(LC_COLLATE, "zh_CN.UTF-8") == NULL) {
        printf("\n警告：无法设置 zh_CN.UTF-8 locale，可能系统未安装该语言包\n");
        return 1;
    }

    printf("\n=== 中文 locale（zh_CN.UTF-8） ===\n");

    printf("用strcmp比较 %s 和 %s: %d\n", str, str2, strcmp(str, str2));
    printf("比较 %s 和 %s: %d\n", str, str2, strcoll(str, str2));
    // 预期：苹果（p） < 香蕉（x） → 返回负数
    printf("比较 %s 和 %s: %d\n", str2, str3, strcoll(str2, str3));
    // 预期：香蕉（x） > 橙子（c） → 返回正数
    printf("用strcmp比较 %s 和 %s: %d\n", str, str3, strcmp(str, str3));
    printf("比较 %s 和 %s: %d\n", str, str3, strcoll(str, str3));
    // 预期：苹果（p） > 橙子（c） → 返回正数



     // --------------------------
    // 场景 1：中文比较（苹果 vs 橙子）
    // --------------------------
    const char *cn1 = "苹果";  // 拼音：píngguǒ
    const char *cn2 = "橙子";  // 拼音：chéngzi

    // 场景 2：带重音的英文（café vs cafe）
    // café（法语“咖啡”，重音字符 é）和 cafe（英文）
    const char *en1 = "café";  // UTF-8 编码：0x63 0x61 0x66 0xC3 0xA9
    const char *en2 = "cafe";  // UTF-8 编码：0x63 0x61 0x66 0x65


    // 1. 默认 locale（C/POSIX，无文化排序规则）
    printf("=== 默认 locale（C/POSIX） ===\n");
    // strcmp：纯字节比较
    printf("strcmp(苹果, 橙子) = %d  ", strcmp(cn1, cn2));
    printf("（按字节值：苹果的首字节 0xE8 > 橙子的首字节 0xE6）\n");

    printf("strcmp(café, cafe) = %d  ", strcmp(en1, en2));
    printf("（按字节值：é的字节 0xC3 0xA9 > e的字节 0x65）\n");

    // strcoll：默认等价于 strcmp
    printf("strcoll(苹果, 橙子) = %d（与strcmp相同）\n", strcoll(cn1, cn2));
    printf("strcoll(café, cafe) = %d（与strcmp相同）\n", strcoll(en1, en2));


    // 2. 中文 locale（zh_CN.UTF-8，按拼音排序）
    printf("\n=== 中文 locale（zh_CN.UTF-8） ===\n");
    setlocale(LC_COLLATE, "zh_CN.UTF-8");
    printf("strcoll(苹果, 橙子) = %d  ", strcoll(cn1, cn2));
    printf("（按拼音：苹果p > 橙子c → 正数）\n");
    printf("strcmp(苹果, 橙子) = %d（仍按字节比较，结果不变）\n", strcmp(cn1, cn2));


    // 3. 英文 locale（en_US.UTF-8，重音字符视为等价）
    printf("\n=== 英文 locale（en_US.UTF-8） ===\n");
    setlocale(LC_COLLATE, "en_US.UTF-8");
    printf("strcoll(café, cafe) = %d  ", strcoll(en1, en2));
    printf("（按文化规则：é 等价于 e → 相等）\n");
    printf("strcmp(café, cafe) = %d（仍按字节比较，结果不变）\n", strcmp(en1, en2));

     setlocale(LC_COLLATE, "");
     printf("strcoll(北京, 上海) = %d  ", strcoll("北京", "上海")); //此时返回-1
        printf("strcmp(北京, 上海) = %d  ", strcmp("北京", "上海")); //此时返回1

        char *collate_locale = setlocale(LC_COLLATE, NULL);
    printf("排序规则（LC_COLLATE）对应的 locale: %s\n", collate_locale);
    return 0;
}
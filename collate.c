#include <stdio.h>
#include <locale.h>

int main() {
    // 初始状态：默认 locale 为 "C"
    printf("初始 LC_COLLATE: %s\n", setlocale(LC_COLLATE, NULL));

    // 设置为系统默认 locale（如 zh_CN.UTF-8）
    char* new_locale = setlocale(LC_COLLATE, "");
    printf("设置后 LC_COLLATE: %s\n", new_locale);

    // 再次查询当前 locale（不修改设置）
    printf("再次查询 LC_COLLATE: %s\n", setlocale(LC_COLLATE, NULL));

    return 0;
}
#include <stdio.h>
#include <locale.h>

void writelines(char *lineptr[], int nlines) 
{ 
    while (nlines-- > 0) 
    printf("%s\n", *lineptr++); //这边可以变
} 
int main(){
    //setlocale(LC_COLLATE,"");

    
    char amessage[] = "nw is the time";
    printf("amessage = %c\n",*amessage);
    printf("amessage1 = %c\n",*(amessage+1));
    
    
    char *bmsg[] = {"nw is the time","nw"};
    printf("b = %c\n",**bmsg); /*指向第一个字符n*/
    //printf("b1 = %c\n",*bmsg++); //lvalue required as increment operand

    writelines(bmsg,2);
    
    setlocale(LC_ALL, "zh_CN.UTF-8");
    printf("%s","世界你好\n");



     // 如果使用宽字符和wprintf
    wchar_t wstr[] = L"你好，宽字符世界！";
    wprintf(L"%ls\n", wstr);

    int arr[] = {10, 20, 30, 40};
    printf("arr = %d\n", *arr); // 输出 b = 10, *p = 20


    int *p = arr; // p 指向数组的第一个元素

    // *p++ 的情况
    int b = *p++; //  *p++ 表达式的结果是 *p 解引用之前的值，即指针 p 自增之前的内存位置中的值。
    //重要的是要理解，尽管指针 p 在表达式求值后自增了，但表达式的结果是自增之前的解引用值。
    printf("b = %d, *p = %d\n", b, *p); // 输出 b = 10, *p = 20


    int a[][2] = {

        {1,2},
        {3,4},
        {5,6}
    };
    printf ("%x \n",&a); //8bff700 
    printf ("%x \n",&a +1); //8bff718 
    //相差24
}
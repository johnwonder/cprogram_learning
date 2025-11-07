#include <stdio.h>
#include <stdint.h>
#include <sys/time.h>
#include <unistd.h>

void func(uint32_t num) {
    printf("Inside func, num: %u\n", num);
}

int main() {
    //long long int large_value = 4294967298L; // 2^32
    struct timeval tv; //局部变量 函数执行完后释放内存
    gettimeofday(&tv,NULL);

    long l = tv.tv_sec^tv.tv_usec^getpid();
       printf("tv_sec:%ld,tv_usec:%ld,getpid:%d, num: %ld\n",tv.tv_sec,tv.tv_usec,getpid(), l);
    func(l); //自动截断 变为2

    unsigned int num1 = 1762334843;
    unsigned int num2 = 216461;
    unsigned int num3 = 36952;
    unsigned int result = num1 ^ num2 ^ num3;
    printf("The result is: %u\n", result);
 
 printf("sizeof(long): %zu\n", sizeof(long));

  printf("sizeof(long long): %zu\n", sizeof(long long));
 printf("sizeof(void*): %zu\n", sizeof(void*));
  
    return 0;
}
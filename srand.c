
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h> // 对于POSIX系统，Windows下使用 <process.h> 及 _getpid

int main(){

    printf("%d \n",time(NULL));
 printf("The value of RAND_MAX: %d\n", RAND_MAX);
    srand(time(NULL)^getpid());
    for (int i = 0; i < 1125; i++) {
        int random_number = rand();
        printf("%d ", random_number);
    }
    return 0;
}
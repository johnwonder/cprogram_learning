#include <stdio.h>
#include <time.h>


int main(){

    time_t current_time;

    time_t *timer = &current_time;

    printf("%ld\n",time(timer));

    printf("%ld\n",(long)*timer);

    printf("%ld\n",(long)*timer);
}
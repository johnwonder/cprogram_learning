#include <stdio.h>


typedef struct standardConfig {

    const char *name; /* The user visible name of this config */
}  standardConfig;

#define createBoolConfig(sname) { \
    .name = sname, \
}

int main(){

    standardConfig configs[] = { 
    
        createBoolConfig("config"),
    
    };

    printf(configs[0].name);


}
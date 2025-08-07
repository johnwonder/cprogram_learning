#include <stdio.h>

int main(){
    // char a;
    // printf("Please enter a character: ");
    // a = getchar();
    // //换行符 \n 的 ASCII 码值是 ‌10‌
    // printf("You entered: %d\n", a);

    int d,nd;
    nd =0;
    while ((d = getchar()) != EOF)
    {
        if(d == ' ')
            ++nd;
        else if(nd > 0){
            putchar(' ');
            nd =0;
            putchar(d);
        }
        else 
            putchar(d);
       
           
        
      
        /* code */
    }
    
    
    
    int c;

//  c =getchar();
//  while (c != EOF)
//  {
    
//     putchar(c);
//     c =getchar();
//  };

//  printf("%d\n",getchar() == EOF);
 
//  printf("EOF: %d", EOF);

long nc;

nc =0;

while (getchar() != EOF)
{
    nc++;
}
printf("%ld\n",nc);



}
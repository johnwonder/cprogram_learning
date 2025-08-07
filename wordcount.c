#include <stdio.h>
#define IN 1
#define OUT 0

int main(){

   int c,nl,nw,nc,state;

   state = OUT;
   nl = nw = nc = 0;
   while ((c = getchar()) != EOF)
   {
      ++nc;
      if(c == '\n')
        ++nl;//行数
      if(c == ' ' || c == '\n' || c == '\t')
          state = OUT; //不在单词内
      else if(state == OUT){
            state = IN;
            ++nw; //单词增加
      }
        
   }

   printf("%d %d %d\n",nl,nw,nc);
   

}
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXTOKEN 100

#define BUFSIZE 100

enum {NAME,PARENS,BRACKETS};

void dcl(void);
void dirdcl(void);

int gettoken(void);
int tokentype;
char token[MAXTOKEN];
char name[MAXTOKEN];
char datatype[MAXTOKEN];
char out[1000];

char buf[BUFSIZE];
int bufp = 0;


// void qsort(void *v[],int left,int right,
//     int (*comp)(void *,void *)){

//         int i,last;

//         void swap(void *v[],int,int);

//         for (i = 0; i < right; i++)
//         {   
//             if(comp(v[i],v[left])< 0){
//                swap(v,++last,i);
//             }
            
//         }
        
// }

int main(){
    
    while (gettoken() != EOF)
    {
        //获取数据类型
        strcpy(datatype,token);
        out[0] = '\0';
        dcl();
        if(tokentype != '\n')
            printf("syntax error\n");

        printf("%s: %s %s\n",name,out ,datatype);
        /* code */
    }
    return 0;
   

}

void dcl(void){

    int ns;
    //读
    for (ns = 0; gettoken() == '*';)
        ns++;

    dirdcl();
    while (ns-- > 0)
    {
         strcat(out," pointer to");
    }
 
}

void dirdcl(void){

    int type;

    if(tokentype == '('){
        dcl();
        if(tokentype != ')')
            printf("erro: missing )\n");
    }
    else if (tokentype == NAME)
    {
        strcpy(name,token);
        /* code */
    }
    else 
        printf("error: expected name or (dcl)\n");

    while ( (type =gettoken()) == PARENS || type == BRACKETS)
    {
        if(type == PARENS)
            strcat(out," function returning");
        else{
            strcat(out," array");
            strcat(out,token);
            strcat(out," of");
        }
        /* code */
    }
    
    

}

int gettoken(void){

    int c,getch(void); //getch
    void ungetch(int);
    char *p = token;

    //当获取到空格或者制表符时继续获取下个字符
    while ((c = getch()) == ' ' || c == '\t');

   if (c == '(') { 
           if ((c = getch()) == ')') { 
               strcpy(token, "()"); 
               return tokentype = PARENS; 
           } else { 
               ungetch(c); 
               return tokentype = '('; 
           } 
       } else if (c == '[') { 
           for (*p++ = c; (*p++ = getch()) != ']'; ) 
               ; 
           *p = '\0'; 
           return tokentype = BRACKETS; //获取到括号
       } else if (isalpha(c)) { 
            //isalpha 函数是 C 语言标准库中的一个函数，用于检查给定的字符是否为字母
           for (*p++ = c; isalnum(c = getch()); ) 
               *p++ = c; 
           *p = '\0'; 
           ungetch(c); 
           return tokentype = NAME; 
       } else 
           return tokentype = c; 
     
    
}

int getch(void){
    return (bufp > 0) ? buf[--bufp] :getchar();
}

void ungetch(int c){
    if(bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++]=c;
}

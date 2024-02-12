%{
#include <stdio.h>
#include <conio.h>

void yyerror(char *);
int yylex();
FILE *fp;
%}

%start S
%%
S : D;{printf("ok");}
D : A B C D | ;
A : 'a' | 'b' | 'c';
B : 'a' | 'b' | 'c';
C : 'a' | 'b' | 'c';  
%%                  
void yyerror(char *err){
     printf("khata darad: %s",err);
}

int yylex(){
   char ch;

   do{
     ch=fgetc(fp);
   }while(ch==' ' || ch=='\t' || ch=='\n');

   return ch;
}

int main(){
    fp=fopen("fileInput.txt","r");
    yyparse();

return 1;
}
%{
#include <stdio.h>
#include <string.h>
//FILE *fp;
void yyerror(char *);
int yylex();
%}
%token IF,WHILE,ID,LE
%start st
%%
st : main {printf("ok");}
main : '+' main |'-' main |'(' main |')' main |IF main|WHILE main |ID main|LE main|;
%%
void yyerror(char *err){
   printf("khataye syntax");
}

//#include "myLex.c"

#include "lex.yy.c"

int main(){
    //fp=fopen("prog.txt","r");
    yyin=fopen("prog.txt","r");
    yyparse();
return 1;
}

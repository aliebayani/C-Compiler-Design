%{
#include <stdio.h>
#include <conio.h>
#include <string.h>

void yyerror(char *);
int yylex();
FILE *fp;
%}
%token Id , Digit , Main ,IF , ELSE , WHILE , FOR , LI , LE , GR , GE , EQ , NEQ , PLUSPLUS , PLUSASSG , ADD
%start S
%%

S : PROG;{printf("ok");}

PROG : Main '(' ')' 
       '{' 
          STMTS
       '}';
STMTS : stmt STMTS | ;
stmt : exprStmt | ifStmt | whileStmt | forStmt;
exprStmt : arthStmt;

arthStmt : Id '=' Operand arthOP Operand';' | Id '=' Operand ';' ;
Condition : Operand RelOper Operand ;

Operand: Id | Digit;
RelOper : LI | LE| GR | GE | EQ | NEQ  ;
arthOP : ADD | '*' | '/' ;

ifStmt : IF '(' Condition ')' '{' STMTS '}' elseStmt;
elseStmt : ELSE '{' STMTS '}'| ;
whileStmt : WHILE '(' Condition ')' '{' STMTS '}' ;
forStmt : FOR '(' ')' '{' STMTS '}';

%%                  
void yyerror(char *err){
     printf("khata darad: %s",err);
}

//#include "lexer2.c"

#include "lex.yy.c"

int main(){
    fp=fopen("fileInput.txt","r");
    yyparse();

return 1;
}
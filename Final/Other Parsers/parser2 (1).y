%{
#include <stdio.h>
#include <conio.h>
#include <string.h>

void yyerror(char *);
int yylex();
FILE *fp;
%}
%token Id,Digit,Main,IF
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

arthStmt : Id '=' AD OPER AD';' ;
AD: Id | Digit;
OPER : '+' | '*' | '/' ;

ifStmt : IF '(' Condition ')' '{' STMTS '}' ;
Condition : AD RelOper AD ;
RelOper : '>' | '<'  ;

whileStmt : ;
forStmt : ;

%%                  
void yyerror(char *err){
     printf("khata darad: %s",err);
}

int yylex(){
   #define NULL '\0'

   char ch;
   char token[101];
   int top=0;

   do{ //WS
     ch=fgetc(fp);
     if(ch==' ' || ch=='\t' || ch=='\n')
         printf("%c ",ch);
   }while(ch==' ' || ch=='\t' || ch=='\n');
   
   if((ch>='a' && ch<='z')||(ch>='A' && ch<='Z')){//ID and Resereved Key
	top=0;
        token[top]=ch;
        ch=fgetc(fp);
        while((ch>='a' && ch<='z')||(ch>='A' && ch<='Z')||(ch>='0' && ch<='9')||(ch=='_')){
	   top++;
	   token[top]=ch;
	   ch=fgetc(fp);
	}
	ungetc(ch,fp);
        top++;
	token[top]=NULL;
	printf(" %s ",token);

	//---- R.key or Id
        if(strcmp(token,"main")==0){
           return Main;
        }else if(strcmp(token,"if")==0){
	   return IF;
	}else{
           // is Identifier
	   return Id;
        }
   }else if(ch>='0' && ch<='9'){//DIGIT
        top=0;
        token[top]=ch;
	ch=fgetc(fp);
        while(ch>='0' && ch <='9'){
	    top++;
	    token[top]=ch;
	    ch=fgetc(fp);
	}
	ungetc(ch,fp);// charekteri ke baese khroj az halge shode bud ra barmigrdanim.
        top++;
        token[top]=NULL;
        printf(" %s " , token);
	return Digit;
   }else{
        printf(" %c ",ch);
	return ch;
   }
}

int main(){
    fp=fopen("fileInput.txt","r");
    yyparse();

return 1;
}
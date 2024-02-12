%{
#include <stdio.h>
/*
#define IF 257
#define WHILE 258
#define ID 259
#define LE 260
*/
%}

%%
([ \t\n])*     		    {printf("\n");}
"if"    		    {ECHO;return IF;}
"while" 		    {ECHO;return WHILE;}
"else"                      {ECHO;return ELSE;}
"main"           	    {ECHO;return MAIN;}
"return"         	    {ECHO;return RETURN;}
"int"            	    {ECHO;return INT;}
"float"          	    {ECHO;return FLOAT;}
"char"           	    {ECHO;return CHAR;}
"for"            	    {ECHO;return FOR;}
"+"                         {ECHO;return '+';}
"++"                        {ECHO;return '++';}
"+="                        {ECHO;return '+=';}
"-"                         {ECHO;return '-';}
"-="                        {ECHO;return '-=';}
"--"                        {ECHO;return '--';}
"*"                         {ECHO;return '*';}
"*="                        {ECHO;return '*=';}
"/"                         {ECHO;return '/';}
"/="                        {ECHO;return '/=';}
"%"                         {ECHO;return '%';}
">"                         {ECHO;return '>';}
">="                        {ECHO;return '>=';}
"<"                         {ECHO;return '<';}
"<="                        {ECHO;return '<=';}
"="                         {ECHO;return '=';}
"=="                        {ECHO;return '==';}
"!="                        {ECHO;return '!=';}
"!"                         {ECHO;return '!';}
"&"                         {ECHO;return '&';}
"&&"                        {ECHO;return '&&';}
"|"                         {ECHO;return '|';}
"||"                        {ECHO;return '||';}
"("     		    {ECHO;return '(';}
")"     		    {ECHO;return ')';}
([a-zA-Z])([a-zA-Z0-9_])*   {ECHO; return ID;}
.*      		    {return -1000;}
%%
int yywrap(){
    return 1;
}
/*
int main(){
	yyin=fopen("prog.txt","r");
	yylex();
return 0;
}
*/

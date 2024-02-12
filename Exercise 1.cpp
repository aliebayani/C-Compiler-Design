#include <stdio.h>
#include <conio.h>

#define True 1
#define False 0

FILE *fp;
int isReservedKey(char []);

int main()
{
	char ch;
	char token[101];
	int  index = 0;

	fp = fopen("prog1.cpp","r");     // read   ,   write    ,    r/w
	
	while (!feof(fp))
	{
		//0
		ch = fgetc(fp);
		
		if (ch == '<')              //0-1
		{   
			    //1
			index = 0;
			token[index] = ch;
			
			ch = fgetc(fp);
			
			if (ch == '=') {        //1-1
				//2
				index++;
				token[index] = ch;
				
				index++;
				token[index] = '\0';
				
				printf("token: LE , %s \n", token);
			}
			
			else if (ch == '>') {   //1-2
				//3	
				index++;
				token[index] = ch;
				
				index++;
				token[index] = '\0';
				
				printf("token: NE , %s \n", token);
			}
			
			else {                  //1-3
				//4
				index++;
				token[index] = '\0';
					
				printf("token: LT , %s \n", token); 
				ungetc(ch,fp);
			}	
		}
		
		
		else if(ch == '=')          //0-2
		{
			    //5	
			index = 0;
			token[index] = ch;
			
			ch = fgetc(fp);
			
			if(ch == '=') {         //5-1
				//7
				index++;
				token[index] = ch;
				
				index++;
				token[index] = '\0';
				
				printf("token: EQ , %s \n", token);	
			}
			
			else {                  //5-2
				//8
				index++;
				token[index] = '\0';
				
				printf("token: ASG , %s \n", token);
				ungetc(ch,fp);
			}
		}
		
		
		else if(ch == '>')          //0-3
		{
			    //6
			index = 0;
			token[index] = ch;
			
			ch = fgetc(fp);
			
			if(ch == '=') {         //6-1
				//9
				index++;
				token[index] = ch;
				
				index++;
				token[index] = '\0';
				
				printf("token: GE , %s \n", token);
			}
			
			else {                  //6-2
				//10
				index++;
				token[index] = '\0';
				
				printf("token: GT , %s \n", token);
				ungetc(ch,fp);
			}	
		}
		
		else if(ch == '+')          //0-4
		{
			    //11
			index = 0;
			token[index] = ch;
			
			ch = fgetc(fp);
			
			if(ch == '+') {         //11-1
				//12
				index++;
				token[index] = ch;
				
				index++;
				token[index] = '\0';
				
				printf("token: INC , %s \n", token);
			}
			
			else if(ch == '=') {    //11-2
				//13
				index++;
				token[index] = ch;
				
				index++;
				token[index] = '\0';
				
				printf("token: ADDASG , %s \n", token);
			}
			
			else {                  //11-3
				//14
				index++;
				token[index] = '\0';
				
				printf("token: ADD , %s \n" , token);
				ungetc(ch,fp);
			}
		}
		
		
		else if(ch == '-')          //0-5
		{
			    //15
			index = 0;
			token[index] = ch;    
			
			ch = fgetc(fp);
			
			if(ch == '-') {         //15-1
				//16
				index++;
				token[index] = ch;
				
				index++;
				token[index] = '\0';
				
				printf("token: DEC , %s \n", token);
			}
			
			else if(ch == '=') {    //15-2
				//17
				index++;
				token[index] = ch;
				
				index++;
				token[index] = '\0';
				
				printf("token: SUBASG , %s \n", token);
			}
			
			else {                  //15-3
				//18
				index++;
				token[index] = '\0';
				
				printf("token: SUB , %s \n", token);
				ungetc(ch,fp);
			}	
		}
		
		
		else if(ch == '*')          //0-6
		{
			    //19
			index = 0;
			token[index] = ch;
			
			ch = fgetc(fp);
			
			if(ch == '*') {         //19-1
				//20
				index++;
				token[index] = ch;
				
				index++;
				token[index] = '\0';
				
				printf("token: MUL , %s \n", token);
			}
			
			else if(ch == '=') {    //19-2
				//21
				index++;
				token[index] = ch;
				
				index++;
				token[index] = '\0';
				
				printf("token: MULASG , %s \n", token);
			}
			
			else {                  //19-3
				//22
				index++;
				token[index] = '\0';
				
				printf("token: MUL , %s \n", token);
				ungetc(ch,fp);
			}	
		}
		
		
		else if(ch == '/')          //0-7
		{
			    //23
			index = 0;
			token[index] = ch;
			
			ch = fgetc(fp);
			
			if(ch == '/') {         //23-1
				//24
				index++;
				token[index] = ch;
				
				index++;
				token[index] = '\0';
				
				printf("token: DIV , %s \n", token);
			}
			
			else if(ch == '=') {    //23-2
				//25
				index++;
				token[index] = ch;
				
				index++;
				token[index] = '\0';
				
				printf("token: DIVASG , %s \n", token);
			}
			
			else {                  //23-3
				//26
				index++;
				token[index] = '\0';
				
				printf("token: DIV , %s \n", token);
				ungetc(ch,fp);
			}
		}
		
		
		else if(ch == '%')          //0-8
		{
		        //27
		    index = 0;
			token[index] = ch;
			
			ch = fgetc(fp);
			
			if(ch == '%') {         //27-1
				//28
				index++;
				token[index] = ch;
				
				index++;
				token[index] = '\0';
				
				printf("token: MODE , %s \n", token);
			}
			
			else if(ch == '=') {    //27-2
				//29
				index++;
				token[index] = ch;
				
				index++;
				token[index] = '\0';
				
				printf("token: MODEASG , %s \n", token);
			}
			
			else {                  //27-3
				//30
				index++;
				token[index] = '\0';
				
				printf("token: MODE , %s \n", token);
				ungetc(ch,fp);
			}
		}
		
		
		else if(ch >= '0' && ch <= '9')
		{                          //0-9  Number
			index = 0;
			token[index] = ch;
			
			ch = fgetc(fp);
			
			while(ch >= '0' && ch <= '9')
			{                      //int 
				index++;
				token[index] = ch;
				
				ch = fgetc(fp);
			}
			
			
			if(ch == '.')
			{                     //float 
				index++;
				token[index] = ch;
				
				ch = fgetc(fp);
				
				while(ch >= '0' && ch <= '9')
				{                 
					index++;
					token[index] = ch;
					
					ch = fgetc(fp);
				}
					
				ungetc(ch,fp);
				
				index++;
				token[index] = '\0';
				
				printf("token float Number: %s \n", token);             //float 
			} 
			
			else
			{
				ungetc(ch,fp);
				
				index++;
				token[index] = '\0';
				
				printf("token int Number: %s \n", token);               //int
			}
			
		}
		
		else if((ch >= 'A' && ch <= 'Z')||(ch >= 'a' && ch <= 'z')) 
		{                                                              // 0-10 Id &  Reserved Key
			index = 0;
			token[index] = ch;
			
			ch = fgetc(fp);
			
			while((ch >= 'A' && ch <= 'Z')||(ch >= 'a' && ch <= 'z')||(ch >= '0' && ch <= '9')||(ch == '_')) {
				index++;
				token[index] = ch;
				
				ch = fgetc(fp);
			}
			ungetc(ch,fp);
			
			index++;
			token[index] = '\0';
			
			if(isReservedKey(token) == True)
			{
				printf("token reserved Key: %s \n", token);
			}
			else
			{
				printf("token ID: %s \n", token);	
			}	
			
		else                    
		{
			putchar(ch);
		}
			
	}
		
	return 0;
}

//---------------------------------------------------------------------------------------------

int isReservedKey(char token[])
{
	if(strcmp(token, "if") == 0)
	{
		//printf("token Reserved Key: %s \n",token);//if
		return True;
	}
	else if(strcmp(token, "else") == 0) {
		//printf("token Reserved Key: %s \n", token);//else
		return True;
	}
	else if(strcmp(token, "for") == 0) {
		//printf("token Reserved Key: %s \n", token);//for
		return True;
	}
	else if(strcmp(token, "while") == 0) {
		//printf("token Reserved Key: %s \n", token);//while
		return True;
	}
	else if(strcmp(token, "do") == 0) {
		//printf("token Reserved Key: %s \n", token);//do
		return True;
	}
	else if(strcmp(token, "int") == 0) {
		//printf("token Reserved Key: %s \n", token);//int
		return True;
	}
	else if(strcmp(token, "float") == 0) {
		//printf("token Reserved Key: %s \n", token);//float
		return True;
	}
	else if(strcmp(token, "char") == 0) {
		//printf("token Reserved Key: %s \n", token);//char
		return True;
	}
	else
	{
		return False;
	}
}

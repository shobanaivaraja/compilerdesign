//Creation of symbol table
#include<stdio.h>
   #include<string.h>
   void main(){
   int len,i;
   char input[30];
   clrscr();
   printf("\t\t**Implementation of symbol table**");
   printf("\nEnter instruction");
   scanf("%s",&input);
   printf("\nName\tType");
   len=strlen(input);
 for(i=0;i<len;i++){
   if(isalpha(input[i])){
			   printf("\n%c\tidentifier",input[i]);

   }
   else if(isdigit(input[i])){
	printf("\n%c\tconstant",input[i]);
   }
   else{
	switch(input[i]){
	case '+':
		printf("\n%c\tAddition operator",input[i]);
		break;
	case '-':
		printf("\n%c\tSubtraction operator",input[i]);
		break;
	case '*':
		printf("\n%c\tProduct operator",input[i]);
		break;
	case '%':
		printf("\n%c\tModulo operator",input[i]);
		break;
	case '/':
		printf("\n%c\tDivision operator",input[i]);
		break;
	case '(':
		printf("\n%c\tLeft paranthesis",input[i]);
		break;
	case ')':
		printf("\n%c\tRight parenthesis",input[i]);
		break;
	case '=':
		printf("\n%c\tRight parenthesis",input[i]);
		break;
	}
   }   }   }


#include<stdio.h>
	#include<string.h>
	#include<stdlib.h>
	int check_keyword(char buf[]){
	char keywords[32][10] = {"auto","break","case","const","continue","default", "do","double","else","enum","extern","for","goto","if","return","short","signed","struct","switch","typedef","union","unsigned","void","while"};
	char data[32][10]={"int","char","float"};
	char fun[32][10]={"main","printf"};
	int i, flag = 0;
	for(i = 0; i < 32; ++i){
	if(strcmp(keywords[i], buf) == 0){
	    flag = 1;
	}
	if(strcmp(data[i],buf)==0)
	{
	flag=2;
	} if(strcmp(fun[i],buf)==0)
	{
	flag=3;
	}
	}
	return flag;
	}
	void main()
	{
	char ch,buf[15],operator[]="+-/%=()";
	FILE *fp;
	int i,j=0;
	clrscr();
	printf("\t\t**Develop a lexical analyser to recognize a few patterns**\n");
	fp=fopen("sample.c","r");
	if(fp == NULL){
	printf("error while opening the file\n");
	exit(0);
	}
	while((ch = fgetc(fp)) != EOF){
	for(i=0;i< 6;++i){
	if(ch == operator[i])
			switch(ch){
	case '+':
		printf("\n%c - Addition operator\n",ch);
		break;
	case '-':
		printf("\n%c - Subtraction operator\n",ch);
		break;
	case '*':
		printf("\n%c - Product operator",ch);
		break;
	case '%':
		printf("\n%c- Modulo operator",ch);
		break;
	case '/':
		printf("\n%c - Division operator",ch);
		break;
	case '(':
		printf("%c - Left paranthesis \n ) - Right parenthesis\n",ch);
		break;
	case ')':
		printf("%c - Right parenthesis\n",ch);
		break;
	case '=':
		printf("%c - assignment operator\n ",ch);
		break;
	}
	}
	if(isalnum(ch))
	{
	buf[j++] = ch;
	}
	if((ch == ' ' || ch == '\n') && (j != 0)){
	buf[j] = '\0';
	j = 0;
	if(check_keyword(buf)!= 0)
	{
		if(check_keyword(buf) == 2)
			printf("%s - Datatype\n",buf);
		else if(check_keyword(buf) == 1)
			printf("%s - keyword\n", buf);
		else
			printf("%s - function\n",buf);
	}
	else{
		printf("%s - indentifier\n", buf);
	} }
	}
	fclose(fp);
	}

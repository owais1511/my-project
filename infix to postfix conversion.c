#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#define size 100
char stack[size];
int top= -1;
void push(char item)
{
	if(top>=size-1)
	printf("Overflow!");
	else
	{
		top++;
		stack[top]=item;
	}
}
char pop()
{
	return(stack[top--]);
}
int is_operator(char symbol)
{
	if(symbol=='^'||symbol=='*'||symbol=='/'||symbol=='+'||symbol=='-')
	return 1;
	else
	return 0;
}
int precedence(char symbol)
{
	if(symbol=='^')
	return 3;
	if(symbol=='*'||symbol=='/')
	return 2;
	if(symbol=='+'||symbol=='-')
	return 1;
	else
	return 0;
}
int main()
{
	char infix[size], postfix[size], item, temp;
	int i=0, j=0;
	printf("enter expression \n");
	gets(infix);
	while(infix[i]!='\0')
	{
		item=infix[i];
		if(item=='(')
		push(item);
		else if(item>='A'&& item<='Z' ||item>='a'&& item<='z')
		postfix[j++]=item;
		else if(is_operator(item)==1)
		{
			temp=pop();
			while(is_operator(temp)==1 && precedence(temp)>=precedence(item))
			{
				postfix[j++]=temp;
				temp=pop();
			}
			push(temp);
			push(item);
		}
		else if(item==')')
		{
			temp=pop();
			while(temp!='(')
			{
				postfix[j++]=temp;
				temp=pop();
			}
		}
		else
		{
			printf("invalid expression!");
			getch();
			exit(0);
		}
		i++;
	}
	while(top> -1)
	postfix[j++]=pop();
	printf("postfix expression is: \n");
	puts(postfix);
	getch();
	return 0;
}

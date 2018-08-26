#include<stdio.h>
#include<stdlib.h>
int stack[5], revstack[5];
int top= -1, revtop= -1;
void reverse()
{
	while(top>-1)
	revstack[++revtop]=pop();
}
int pop()
{
	return stack[top--];
}
int main()
{
	int i;
	printf("Enter elements in stack.\n");
	for(i=0;i<5;i++)
	scanf("%d",&stack[++top]);
	reverse();
	printf("Reversed Stack is\n");
	for(i=0;i<5;i++)
	printf("%d\n",revstack[i]);
}

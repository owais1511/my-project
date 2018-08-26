#include<stdio.h>
#include<stdlib.h>
#define NUL 0
struct node
{
	int info;
	struct node * next;
};

void display(struct node*start)
{
	struct node *temp;
	temp=start;
	while(temp!=NUL)
	{
		printf("%d\n",temp->info);
		temp=temp->next;
	}
}
void merge(struct node*start1,struct node*start2)
{
	struct node *temp,*tail,*head=NUL;
	while(start1!=NUL&&start2!=NUL)
	{
		if(start1->info<start2->info)
		{
			temp=(struct node*)malloc(sizeof(struct node));
			temp->info=start1->info;
			temp->next=NUL;
			tail->next=temp;
			tail=temp;
			start1=start1->next;
		}
		else
		{
			temp=(struct node*)malloc(sizeof(struct node));
			temp->info=start2->info;
			tail->next=temp;
			temp->next=NUL;
			tail=temp;
			start2=start2->next;
		}
		if(head==NUL)
		head=temp;
	}
	printf("\nMerged list is...\n");
	printf("___________\n\n");
	display(head);
	printf("___________\n\n");
}
main()
{
	struct node*start1=NUL,*start2=NUL,*ptr1,*ptr2,*tail1=NUL,*tail2=NUL;
	char opt1,opt2;
	printf("LIST 1...\n");
	do
	{
		ptr1=(struct node*)malloc(sizeof(struct node));
		if(start1==NUL)
		{
			start1=ptr1;
			tail1=ptr1;
		}
		else
		{
			tail1->next=ptr1;
			ptr1->next=NUL;
			tail1=ptr1;
		}
		printf("Enter node info\n");
		scanf("%d",&ptr1->info);
		printf("Enter 'y' to continue or any other key to exit\n");
		opt1=getch();
	}while(opt1=='y');
	
	printf("LIST 2...\n");
	do
	{
		ptr2=(struct node*)malloc(sizeof(struct node));
		if(start2==NUL)
		{
			start2=ptr2;
			tail2=ptr2;
		}
		else
		{
			tail2->next=ptr2;
			ptr2->next=NUL;
			tail2=ptr2;
		}
		printf("Enter node info\n");
		scanf("%d",&ptr2->info);
		printf("Enter 'y' to continue or any other key to exit\n");
		opt2=getch();
	}while(opt2=='y');
	printf("\nLIST 1...\n");
		printf("___________\n\n");
	display(start1);
	printf("\nLIST 2...\n");
		printf("___________\n\n");
	display(start2);
	merge(start1,start2);
	getch();
}


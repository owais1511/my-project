#include<stdio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node * next;
};
void display(struct node* start)
{
	struct node *temp;
	temp=start;
	while(temp!=NULL)
	{
		printf("%d\n",temp->info);
		temp=temp->next;
	}
}
void create(struct node * start)
{
	char opt;
	struct node *ptr,*tail=NULL;
	do
	{
		
		ptr=(struct node*)malloc(sizeof(struct node));
		if(start==NULL)
		{
			start=ptr;
			tail=ptr;
		}
		else
		{
			tail->next=ptr;
			ptr->next=NULL;
			tail=ptr;
		}
		printf("Enter node info\n");
		scanf("%d",&ptr->info);
		printf("Enter 'y' to continue or any other key to exit\n");
		opt=getch();
	}while(opt=='y');
	display(start);
}

void concatenate(struct node*start1,struct node*start2)
{
	struct node *temp;
	temp=start1;
	while(temp->next!=NULL)
	temp=temp->next;
	temp->next=start2;
	printf("\nConcatenated List...\n");
	printf("___________\n\n");
	display(start1);
	printf("___________\n\n");
}
main()
{
	struct node*start1=NULL,*start2=NULL;
	char opt;
	printf("Enter list 1...\n");
	printf("____________________\n\n");
	create(start1);
	printf("Enter list 2...\n");
	printf("____________________\n\n");
	create(start2);	
	concatenate(start1,start2);
}


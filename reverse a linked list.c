#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node
{
	int info;
	struct node *next;
};
struct node *create()
{
	struct node *start=NULL;
	char opt;
	do
	{
		struct node *ptr, *tail;
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
		printf("Enter data:\n");
		scanf("%d",&ptr->info);
		printf("Enter 'y' to continue and any other key to end\n");
		opt=getch();
	}while(opt=='y');
	return(start);
}
struct node* reverse(struct node **start)
{
	struct node* rev=NULL,*visit,*ptr;
	visit=*start;
	while(visit!=NULL)
	{
		ptr=(struct node*)malloc(sizeof(struct node));
		ptr->info=visit->info;
		ptr->next=rev;
		rev=ptr;
		visit=visit->next;
	}
	return(rev);
}
void display(struct node **start)
{
	struct node *t;
	if(*start==NULL)
	printf("List is Empty!\n");
	else
	{
		t=*start;
		while(t!=NULL)
		{
			printf("%d\n",t->info);
			t=t->next;
		}
	}
	getch();
}
main()
{
	struct node* start,*rev;
	start=create();
	printf("Entered List is\n");
	display(&start);
	rev=reverse(&start);
	printf("Reversed List is\n");
	display(&rev);
}

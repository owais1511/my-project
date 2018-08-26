#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *next;
};
struct node *top=NULL;
struct node* create()
{
	struct node *ptr;
	ptr=(struct node *)malloc(sizeof(struct node));
	return(ptr);
} 
void push()
{
	struct node *temp;
	temp=create();
	printf("Enter info\n");
	scanf("%d",&temp->info);
	temp->next=NULL;
	if(top==NULL)
	{
		top=temp;
	}
	else
	{
		temp->next=top;
		top=temp;
	}
	printf("Element PUSHED IN...");
	getch();
}
void pop()
{
	struct node* temp;
	int pos,i;
	if(top==NULL)
	{
		printf("Stack is empty\n");
	}
	else
	{
		temp=top;
		top=top->next;
		free(temp);
		printf("Element POPED OUT...");
	}
	getch();
}
void peep()
{
	if(top==NULL)
	{
		printf("Stack is empty\n");
	}
	else
	{
		printf("%d",top->info);
	}
	getch();
}
void view_stack()
{
	struct node *temp;
	if(top==NULL)
	printf("List is Empty!");
	else
	{
		temp=top;
		printf("The stored list is\n");
		while(temp!=NULL)
		{
			printf("-> %d",temp->info);
			temp=temp->next;
		}
	}
	getch();
}
int menu()
{
	int choice;
	printf("\n...STACK (Linked List Implementation)...\n\n");
	printf("1. Push Element.\n");
	printf("2. Pop Element.\n");
	printf("3. Peep in the stack.\n");
	printf("4. View Stack.\n");
	printf("5. Exit.\n");
	printf("Enter your choice:");
	scanf("%d",&choice);
	return (choice);
}
main()
{
	while(1)
	{system("cls");
		switch(menu())
		{
			case 1:
				push();
				break;
				case 2:
					pop();
					break;
					case 3:
						peep();
						break;
					    case 4:
							view_stack();
							break;
							case 5:
								exit (0);
								break;
								default:
									printf("\nInvalid choice.\n");
									getch();
		}
	}
}

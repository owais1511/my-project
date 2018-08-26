#include<stdio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node * next;
};
struct node*start=NULL;
void create_node()
{
	struct node *ptr,*tail=NULL;
	char opt;
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
	
}
void insert_begin()
{
	struct node* ptr;
	ptr=(struct node*)malloc(sizeof(struct node));
	printf("Enter node info\n");
	scanf("%d",&ptr->info);
	ptr->next=start;
	start=ptr;
}
void insert_end()
{
	struct node* ptr,*tail;
	ptr=(struct node*)malloc(sizeof(struct node));
	printf("Enter node info\n");
	scanf("%d",&ptr->info);
	tail=start;
	while(tail->next!=NULL)
	tail=tail->next;
	tail->next=ptr;
	ptr->next=NULL;
}
void insert_middle()
{
	struct node* ptr,*temp;
	int loc,i;
	ptr=(struct node*)malloc(sizeof(struct node));
	printf("Enter node info\n");
	scanf("%d",&ptr->info);
	printf("Enter location/position of insertion\n");
	scanf("%d",&loc);
	temp=start;
	for(i=0;i<loc-2;i++)
	temp=temp->next;
	ptr->next=temp->next;
	temp->next=ptr;
}
void display_node()
{
	struct node *temp;
	if(start==NULL)
	{
		printf("Empty List.");
	}
	temp=start;
	while(temp!=NULL)
	{
		printf("%d\n",temp->info);
		temp=temp->next;
	}
}
int main()
{
	int choice;
	printf("_____________________________________________  \n\n");
	printf("||  LINKED LIST WITH DIFFERENT OPERATIONS  ||\n");
	printf("_____________________________________________  \n\n");
	printf("1. Create List\n");
	printf("2. Insert Node At Begining\n");
	printf("3. Insert Node At End\n");
	printf("4. Insert Node Anwhere In The Middle\n");
	printf("5. Dispay List\n");
	printf("6. Exit \n");
	printf("_____________________________________________  \n\n");
	while(1)
	{
		printf("Enter your choice: ");
		scanf("%d",&choice);
		printf("_____________________________________________  \n\n");
		switch(choice)
		{
			case 1:
				create_node();
				break;
				case 2:
					insert_begin();
					break;
					case 3:
						insert_end();
						break;
						case 4:
							insert_middle();
							break;
							case 5:
								display_node();
								break;
								case 6:
									exit(0);
									break;
								
		}
	}

}

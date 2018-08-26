#include<stdio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node*left;
	struct node*right;
};
	void preorder(struct node *root)
	{
		if(root!=NULL)
		{
			printf("-> %d ",root->info);
			preorder(root->left);
			preorder(root->right);
		}
	}

main()
{
struct node *root=NULL,*n,*temp,*prev;
char opt;
	do 
	{
		n=(struct node*)malloc(sizeof(struct node));
		n->left=NULL;
		n->right=NULL;
		printf("Enter info\n");
		scanf("%d",&n->info);
		if(root==NULL)
		root=n;
		else
		{
			temp=root;
			while(temp!=NULL)
			{
				prev=temp;
				if(temp->info>n->info)
					temp=temp->left;
					else
					temp=temp->right;
			}
			if(prev->info>n->info)
			prev->left=n;
			else
			prev->right=n;
		}
		printf("Enter y to continue\n");
		opt=getch();
	}while(opt=='y');	
	printf("preorder traversal of BST is\n");
	preorder(root);
}

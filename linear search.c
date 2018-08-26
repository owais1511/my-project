#include<stdio.h>
void linear_search(int A[],int n,int item)
{
	int i,flag=1;
	for(i=0;i<n;i++)
	if(A[i]==item)
	{
		flag=0;
		printf("Search Successful");
		return;
	}
	if(flag==1)
	printf("Search Unsuccessful");
}
main()
{
	int A[]={10,20,5,50,23,89,16,25,55,34};
	int i;
	linear_search(A,10,10);
	getch();
}

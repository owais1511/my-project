//sorted binary search
#include<stdio.h>
void binary_search(int A[],int n,int item)
{
	int l=0,u=n-1,m;
	while(l<=u)
	{
		m=(l+u)/2;
		if(item==A[m])
		{
			printf("Search Successful");
			return;
		}
		if(item>A[m])
		l=m+1;
		else
		u=m-1;
	}
	printf("search Unsuccessful");
}
main()
{
	int A[]={5,12,19,33,54,55,59,67,69,80};
	binary_search(A,10,6);
}

#include<stdio.h>
int A(int n)
{
	if(n<=1)
	return 0;
	printf("%d\n",n);
	B(n-1);
	A(n-2);
}
int B(int n)
{
	if(n<=0)
	return 0;
	B(n-1);
	A(n-1);
	printf("%d\n",n);
}
main()
{
	int n;
	printf("Enter a number: ");
	scanf("%d",&n);
	A(n);
}

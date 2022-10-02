#include<stdio.h>

int main()
{
	int i,j,k,p=3,q=1;
	for(i=1;i<=4;i++)
	{
		for(k=p;k>=1;k--)
		printf(" ");
		for(j=1;j<=q;j++)
		{
			printf("+");
		}
		printf("\n");
		p--;
		q=q+2;
	}
	p=1;
	q=1;
	for(i=1;i<=3;i++)
	{
		for(k=1;k<=p;k++)
		printf(" ");
		for(j=5;j>=q;j--)
		{
			printf("+");
		}
		printf("\n");
		p++;
		q=q+2;
	}
}

#include<stdio.h>
#include<stdlib.h>
int main()
{
	int *a,n,i,j,t=0;
	printf("\nEnter the size : ");
	scanf("%d",&n);
	a=(int*)calloc(n,sizeof(int));
	printf("\nEnter the elements : ");
	for(i=0;i<n;i++)
	{
		scanf("%d",(a+i));
	}
	for(i=0;i<n;i++)
	{
		t=0;
		for(j=0;j<n-1-i;j++)
		{
			if(*(a+j)>*(a+j+1))
			{
				t=*(a+j);
				*(a+j)=*(a+j+1);
				*(a+j+1)=t;
			}
		}
	}
	printf("\nThe arranged array : ");
	for(i=0;i<n;i++)
	{
		printf("%d\t",*(a+i));
	}
}


#include<stdio.h> 
#include<math.h>

long check(long n)
{
	int c=0;
	long num=n,nn=n,d,d1,sum=0,dig,num2=0;
	while(num>0)
	{
		d=num%10;
		c++;
		sum=sum+d;
		num=num/10;
	}
	dig=3-(sum%3);
	while(nn>0)
	{
		d=nn/(pow(10,(c-1)));
		if(d<=dig&&dig>=0)
		num2=num2*10+d;
		else if(d>dig&&dig==0)
		num2=num2*10+d;
		else if(d>dig&&dig!=0)
		{
			num2=num2*10+dig;
			num2=num2*10+d;
			dig=0;
		}
		nn=nn-(d*(pow(10,(c-1))));
		c--;
	}
	if(c>0)
	num2=num2*(pow(10,c));
	if(dig>0)
	num2=num2*10+dig;	
	return num2;	
}

int main()
{
	long n[20000],t,num;
	int i;
	scanf("%ld",&t);
	for(i=0;i<t;i++)
	{
		scanf("%ld",&n[i]);
	}
	for(i=0;i<t;i++)
	{
		if(n[i]%3==0)
		printf("%ld\n",n[i]);
		else
		{
			num=check(n[i]);
			printf("%ld\n",num);
		}
	}
}

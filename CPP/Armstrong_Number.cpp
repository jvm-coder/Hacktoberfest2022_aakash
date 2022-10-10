#include<iostream>
using namespace std;
int main()
{int num,t,remainder,sum=0;
cout<<"Enter the number : ";
cin>>num;
t=num;
while(num!=0)
{remainder=num%10;
sum=sum+remainder*remainder*remainder;
num=num/10;
}
if(sum==t)
{cout<<t<<" is an Armstrong number";
}
else
cout<<t<<" is not an armstrong number";
return 0;}

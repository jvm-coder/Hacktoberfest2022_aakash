//write a code to write rational numbers
//check whether they have anything in common and represent the rational numbers as having no common factor

#include<stdio.h>
#include<stdlib.h>

int Rational(int x,int y);

int main(){
	int num, den;

	printf("Please enter the numerator: ");
	scanf("%d", &num);
	printf("Please enter the denominator: ");
	scanf("%d", &den);
	printf("\n===================================\n\n");

	Rational(num, den);
	printf("\n===================================\n\n");
	return 0;
}

int Rational(int x, int y){
	int rem, a, fn, fd;

	fn=x;
	fd=y;

	if(y==0){
		printf("Error: Denominator can't be zero\n");
		printf("\n===================================\n\n");
		exit(0);
	}

	if(x==0){
                printf("The fraction is 0/%d = 0\n",y);
                printf("\n===================================\n\n");
                exit(1);
        }

	rem = x % y;
	if (rem==0){
		x=x/y;
		y=y/y;
	}
	else 
		a = y%rem;

	if (a==0){
		y=y/rem;
		x=x/rem;
	}

	printf("The fraction is %d/%d = %d/%d", fn,fd,x,y); 
	//printf("\nnum = %d,den = %d", x,y);

	printf("\n");
	return(x,y);
}


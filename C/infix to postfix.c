#include<stdio.h>
#define MAXSIZE 20
struct lifo
{
	char st[MAXSIZE];
	int top;
};
typedef struct lifo STACK;
STACK s;

void push(char x)
{
	s.top = s.top + 1;
	s.st[s.top] = x;
}

char pop()
{
	s.top = s.top - 1;
	return (s.st[s.top+1]);
}

int isp(char x)
{
	if (x == '(')
	{
		return 0;
	}
	else if (x == '+' || x == '-')
	{
	    return 3;
	}
	else if (x == '*' || x == '/')
	{
		return 5;
	}
	else if (x == '^')
	{
		return 7;
	}
	else
	{
	    return -1;
	}
}

int icp(char x)
{
	if (x == '+' || x == '-')
	{
		return 2;
	}
	else if (x == '*' || x == '/')
	{
		return 4;
	}
	else if (x == '^')
	{
		return 6;
	}
	else if (x == '(')
	{
	    return 8;
	}
	else
	{
	    return -1;
	}
}

int main()
{
	int i;
	char exp[20],*e;
	s.top = -1;
	printf("Enter the infix expression:");
	scanf("%s",exp);
	e = exp;
	push('#');
    while(*e != '#')
    {
        if (*e >= 'a' && *e <= 'z' || *e >= 'A' && *e <= 'Z')
		{
			printf("%c", *e);
		}
		else if (*e == '(')
		{
			push(*e);
		}
		else if (*e == ')')
		{
			while (s.st[s.top] != '(')
			{
			    char x = pop();
				printf("%c", x);
			}
		pop();
		}
		else
		{
		    if(s.top == -1)
		    {
		        push(*e);
		    }
		    else
		    {
			   while(isp(s.st[s.top]) >= icp(*e))
			   {
				char x = pop();
				printf("%c", x);
			   }
			push(*e);
		    }
		}
     e++;
	}
	if(s.st[s.top] != '#')
	{
	    char x = pop();
		printf("%c",x);
		s.top = s.top-1;
	}
	else
	{
        pop();
	}
 return 0;
}
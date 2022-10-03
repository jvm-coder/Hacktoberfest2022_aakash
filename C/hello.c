#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //asks user for their name
    string s = get_string("What is your name?\n");
    //prints hello with the user's name
    printf("hello, %s\n", s);
}

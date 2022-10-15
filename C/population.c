#include <cs50.h>
#include <stdio.h>

int main()
{
    // Prompt for start size
    int x;
    int y;
    int n = 0;
    do
    {
        x = get_int("Start size : ");
    }
    while (x < 9);

    // Prompt for end size
    do
    {
        y = get_int("End size : ");
    }
    while (y < x);

    // Calculate number of years until we reach threshold
    while (x < y)
    {
        x = x + (x / 3) - (x / 4);
        n++;
    }

    // Print number of years
    printf("Years : %i\n", n);
}
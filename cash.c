#include <cs50.h>
#include <stdio.h>
#include <math.h>
int main (void)
{
    float qu = 25;
    float dime = 10;
    float five =5;
    float one =1;

    float change;
    do 
    {
    change = get_float("Change owed: ");
    }
    while (change < 0);
    change = change * 100;
    change = round(change);
    int count = 0; 
    while(change >= qu)
    {
        change = change - qu;
        count = count + 1;
    }
    while (change >= dime)
    {
        change = change - dime;
        count = count + 1;
    }
    while (change >= five)
    {
        change = change - five;
        count = count + 1;
    }
    while (change >= one)
    {
        change = change - one;
        count = count + 1;
    }

printf("%i\n",count);
}

//Purpose is to find out how many coins you have used when given a change
//Program intends to use smallest number of coins as possible
#include <cs50.h>
#include <stdio.h>
#include <math.h>
int main(void)
{
    float qu = 25;
    float dime = 10;
    float five = 5;
    float one = 1;

    float change;
    // Ask user for change and accept it as float, keep asking until it is positive
    do 
    {
        change = get_float("Change owed: ");
    }
    while (change < 0);
    // convert it to cents and round it to integer
    change = change * 100;
    change = round(change);
    int count = 0; 
    // Starting from biggest cent, check if it is bigger than it simultaneously substract the remainder and count the loops so that we know how many coins we collected
    while (change >= qu)
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
    // print the result
    printf("%i\n", count);
}

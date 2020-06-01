
#include <cs50.h>
#include <stdio.h>
void draw_right(int height);

int main(void)
{ 
    // Ask the user Height and make sure it is between 1 to 8 inclusive 
    int h;
    do 
    {
        h = get_int("Height ");
    }
    while (h <  1 || h > 8);
    { 
    // Ask the user Height and make sure it is between 1 to 8 inclusive 
    int h;
    do 
    {
        h = get_int("Height ");
    }
    while (h <  1 || h > 8);
    // draw coloumns as high as height(n)
    for (int a = 1; a < h + 1; a++)
    {
        // space numbers decreasing downward
        for (int c = 0; c < h - a; c++)
        {
            printf(" ");
        }
        // hash numbers increasing downward and total of hash and space gives the number of height(n)
        for (int b = 0; b < h - (h - a); b++)
        {
            printf("#");
        }
        printf("\n");
    }
        
}

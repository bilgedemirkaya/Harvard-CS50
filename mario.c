
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
    // I have declared a function what does the same job just for fun
    draw_pyramid(h);

}
void draw_pyramid(int height)
{
    for (int a = 1; a < height + 1; a++)
    {
        // space numbers decreasing downward
        for (int c = 0; c < height - a; c++)
        {
            printf(" ");
        }
        // hash numbers increasing downward and total of hash and space gives the number of height(n)
        for (int b = 0; b < height - (height - a); b++)
        {
            printf("#");
        }
        printf("  ");
        // print the same amount of dash so just copied same for loop after middle space
        for (int b = 0; b < height - (height - a); b++)
        {
            printf("#");
        }
        printf("\n");
    }
}

#include <cs50.h>
#include <stdio.h>
int main(void)
{
    int h;
    do 
    {
        h = get_int("Height ");
    }
    while (h <  1 || h > 8);

    for(int a = 1; a < h+1; a++)
    {
        for(int c = 0; c < h-a; c++)
        {
            printf(" ");
        }
        for(int b = 0; b < h-(h-a); b++)
        {
        printf("#");
        }
        printf("\n");
    }
        
}

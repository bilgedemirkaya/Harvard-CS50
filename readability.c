#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

 int main(void)
{
    int i = 0; 
    string text = get_string("Text: ");
   int n = strlen(text);
   
   for (int c = 0; c < n; c++ )
   {
     
     if (text[c] >= 'a' && text[c] <= 'z')
     {
         i += 1;
     }
     else if(text[c] >= 'A' && text[c] <= 'Z')
     {
         i += 1;
     }
    
   }
   // printf("%i letter(s)\n", i);
    
    int w = 1;
    for (int c = 0; c < n ; c++)
    {
        if (((text[c] == ' ') && (text [c + 1] >= 'a') && (text[c + 1] <= 'z')) || ((text[c] == ' ') && (text [c + 1] >= 'A') && (text[c + 1] <= 'Z')) )
        {
            w += 1;
        }
    }
   // printf("%i word(s)\n", w);
    
    int s = 0;
    for (int c = 0; c < n; c++)
    {
        if((text[c] == '?') || (text[c] == '!') || (text[c] == '.'))
        {
            s += 1;
        }
        
    }
    //printf("%i sentences\n", s);
    
    float L;
    L = ((double)i / (double)w) * 100;
    
    float S;
    S = ((double)s / (double)w) * 100;
    
    //printf("%f\n", L);
    
    //printf("%f\n", S);
    
    float index;
    
    index = (0.0588 * L) - (0.296 * S) - 15.8;
    
    index = round(index);
    
    if (index < 1)
    {
    printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
    printf("Grade %1.f\n", index);
    }
    return 0;
}
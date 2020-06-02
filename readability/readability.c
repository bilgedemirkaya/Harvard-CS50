#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    // get a text from user and grade it
    int i = 0; 
    string text = get_string("Text: ");
    int n = strlen(text);
    // find out the letters used in text in total
    for (int c = 0; c < n; c++)
    {
        if (text[c] >= 'a' && text[c] <= 'z')
        {
            i += 1;
            
        }
        else if (text[c] >= 'A' && text[c] <= 'Z')
        {
            i += 1;
            
        }
        
    }
    
    //printf("%i letter(s)\n", i);
    // find out the word seperated by ' ' in text in total
    int w = 1;
    for (int c = 2; c < n ; c++)
    {
        if (((text[c] == ' ') && (text [c + 1] >= 'a') && (text[c + 1] <= 'z')) || ((text[c] == ' ') && (text [c + 1] >= 'A')
                && (text[c + 1] <= 'Z')))
        {
            w += 1;
        }
    }
    //printf("%i word(s)\n", w);
    //find out the sentences in text in total 
    
    int s = 0;
    for (int c = 0; c < n; c++)
    {
        if ((text[c] == '?') || (text[c] == '!') || (text[c] == '.'))
        {
            s += 1;
        }
        
    }
    //printf("%i sentences\n", s);
    // convert integer values to float type to get the right result
    float L;
    L = ((double)i / (double)w) * 100;
    
    float S;
    S = ((double)s / (double)w) * 100;
    
    //printf("%f\n", L);
    
    //printf("%f\n", S);
    //used the formula for grading the text
    
    float index;
    
    index = (0.0588 * L) - (0.296 * S) - 15.8;
    
    index = round(index);
    // print the result
    
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

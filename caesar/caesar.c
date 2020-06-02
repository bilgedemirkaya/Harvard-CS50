#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

int check_is_digit(char *str);

int main(int argc, char **argv)
{
    char *str = argv[1];
    char *text;
    
     // check if the input is one argument and all digit if not exit the code with error
     
    if (argc != 2 || check_is_digit(argv[1]) != 'n')
    {
        printf("Usage: ./ceasar key");
        return 1;
    }
    // convert the string to integer
    
    int key = atoi(str);
    
    // printf("key is %i\n",key);
    
    //get text input from user
    
    text = get_string("plain text: ");
    
    // manipulating these alphabetic characters in text, by using the key provided. Adding key value into the each character.
    
    for (int a = 0; text[a] != '\0'; a++)
    {
        if (isalpha(text[a]) && isupper(text[a]))
        {
            text[a] = text[a] - 65;
            text[a] = (text[a] + key) % 26;
            text[a] = text[a] + 65;
        }
        else if (isalpha(text[a]) && islower(text[a]))
        {
            text[a] = text[a] - 97;
            text[a] = (text[a] + key) % 26;
            text[a] = text[a] + 97;
        }
        else 
        {
            text[a] = text[a];
            
        }
    }
    
    printf("ciphertext: %s\n", text);
          
}

// function checks if all elements of array is digit. I could use boolean function instead.

int check_is_digit(char *str)
{
    int count = 0;
    char n = 'n';
    
    for (int j = 0; str[j] != '\0'; j++)
    {
        if (isdigit(str[j]) != 0)
        {
            count++;
        }
        else
        {
            return 1;
        }
    }
    
    return n;
}

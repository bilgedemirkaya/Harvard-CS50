int check_is_valid(char *str);

int main(int argc, char **argv)
{
    char *str = argv[1];
    char *text;
    
// the only difference is when user put unvalid key, it keeps asking until key is valid.

    if (argc != 2 || check_is_valid(argv[1]) != 'n')
    {
        do
        {
       
            str = get_string("Usage: ./ceasar key ");
            
        }
        
        while (check_is_valid(str) != 'n'  || argc != 2);
        
    }
    
    int key = atoi(str);
    
       printf("key is %i\n",key);
        text = get_string("plain text: ");
        
        for (int a = 0; text[a] != '\0'; a++)
        {
            if (isalpha(text[a]) && isupper(text[a]))
            {
                text[a] = text[a] - 65;
                text[a] = (text[a] + key) % 26;
                text[a] = text[a] + 65;
            }
            else if(isalpha(text[a]) && islower(text[a]))
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
        printf("ciphertext: %s\n",text);
          
}

int check_is_valid(char *str)
{
    int count = 0;
    char n = 'n';
 
    

        for(int j = 0; str[j] != '\0'; j++)
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

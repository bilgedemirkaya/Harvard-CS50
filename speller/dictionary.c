// Implements a dictionary's functionality
#include "dictionary.h"

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// to keep track of how many words in dictionary in total
int totalwords = 0;

//Returns true if word is in dictionary else false
bool check(const char *word)
{
    
    int i = hash(word);
    // table[i] is now our linked list we want to search
    
    
    /*cursor is equal to table[i]
    it will go to next element in the chain,until it hits NULL
    for each element it will compare strings*/
    for (node *cursor = table[i]; cursor != NULL; cursor = cursor ->next)
    {
        if (strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }

    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    int n = (int) tolower(word[0]) - 97;
    return n;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // char array to store strings readed from ptr to dictionary
    char words[LENGTH];
    // return value of hash function
    int x;
  
    // fopen opens up the dictionary file, and return a pointer to it.
    FILE *dicptr = fopen(dictionary, "r");
    
    // check if the file is empty
    if (dicptr == NULL)
    {
        printf("Could not open the file\n");
        return false;
    }
    
    // Read strings from the file (fread is to read binary data and it reads to another structure; to read the text we will use fscanf)
    while (fscanf(dicptr, "%s", words) != EOF)//EOF = end of file
    { 
        // fscanf returns EOF when it is the end
        // create a memory (for a node) for each of the word we readed
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            printf("No memory left\n");
            return false;
        }
        //copy words into node
        strcpy(n ->word, words);
        totalwords += 1;
        
        //hash function returns an integer which indicates the location of word in hash table.
        int i = hash(words);
        
        //node points to table[i] first so rest of the list will not be lost
        n ->next = table[i];
        
        // now ith of table becomes the first node
        table[i] = n;
    }
    
    fclose(dicptr);
 
    
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    
    return totalwords;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{ 
    node *tmp;
    node *cursor;

    // it will keep doing until the last elemnt of linked lists
    for (int i = 0; i < N; i++)
    {
        if (table[i] == NULL)
        {
            continue;
        }

        cursor = table[i];
        tmp = cursor;

        // tmp and cursor will point the elements of linked list by one by 
        while (cursor->next != NULL)
        {
            cursor = cursor->next;
            free(tmp);
            tmp = cursor;
        }
        free(cursor);
        // It will free whats behind in the list, not in front of it
    }
    return true;
}

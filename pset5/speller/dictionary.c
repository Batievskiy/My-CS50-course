// Implements a dictionary's functionality

#include <stdbool.h>

#include "dictionary.h"

/* this is detailed explanation for beginners in programming like me.)

 * here I found a comprehensive collection of hash functions
 * http://www.cse.yorku.ca/~oz/hash.html
 * We gonna use first from the list - djb2
 * there is gonna be 5381 buckets in hash table to work with

djb2
 * this algorithm (k=33) was first reported by dan bernstein many years ago
 * in comp.lang.c. another version of this algorithm uses xor:
 * hash(i) = hash(i - 1) * 33 ^ str[i];
 * the magic of number 33 (why it works better than many other constants, prime or not)
 * has never been adequately explained.

unsigned long hash(unsigned char *str)
{
    unsigned long hash = 5381;
    int c;

    while (c = *str++)
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    return hash;
}
*/

#include <string.h>
#include <strings.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// this is our 5381 buckets we gonna use in hash table using djb2 algorythm
const unsigned int HASH_TABLE_SIZE = 5381;

// this structure is represents a node in a hash table
// something like this: [word0, *next-]--> [word1, *next-]--> [word2, *next-]--> NULL
typedef struct node
{
    char word[LENGTH + 1]; // word length (max is 45 in dictionary.h) + one for "\0" ending
    struct node *next; // and pointer to next node
}
node;

// const unsigned int N = HASH_TABLE_SIZE;

// this is out hash table of pointers to work with
// something like this: [*node0, *node1, *node2, ...]
// this hashTable is gonna have the adresses to nodes
// where we gonna store our words
node *hashTable[HASH_TABLE_SIZE];

// here we have number of words in dictionary
unsigned int numWordsDic = 0;

// and hashIndex from the word
unsigned int hashIndex = 0;

// here we check if words in dictionary and returns true
// and false if not in the dictionary
bool check(const char *word)
{
    // assigh index of current word to hashIndex
    hashIndex = hash(word);

    // create temporary current node
    node *currentNode = hashTable[hashIndex]; // copy value from our hash table at current index

    while (currentNode != NULL) // proceed until end of table
    {
        if (strcasecmp(currentNode->word, word) == 0) // strcasecmp - compare two strings ignoring case and return 0 if equal
        {
            return true; // if word equal
        }
        currentNode = currentNode->next; // copy its value to next pointer
    }
    return false;
}

// Hashes word to a hashIndex for `bool check`
// I just copied that from `djb2` hash function
unsigned int hash(const char *word)
{
    unsigned long hash = HASH_TABLE_SIZE;
    int c;

    while ((c = tolower(*word++))) // we need to keep our words lowercase
    {
        hash = ((hash << 5) + hash) + c; // hash * 33 + c // its a kind of Magic, magic, magic.)))
    }
    return hash % HASH_TABLE_SIZE;
}

// now we have to load dictionary into memory
// and returning true if successful, and false if not succesful
bool load(const char *dictionary)
{
    //let's create temporary string `word` to work with
    char tempWord[LENGTH + 1]; // word length (max is 45 in dictionary.h) + one for "\0" ending

    // first of all we create pointer and open a FILE to `read`
    FILE *ptrDic = fopen(dictionary, "r");

    // check if this pointer points to nothing
    if (ptrDic != NULL)
    {
        // and scan each word in dictionary
        while (fscanf(ptrDic, "%s", tempWord) != EOF) // until we find end of file in dictionary
        {
            //allocating some memory for current node
            node *currentNode = malloc(sizeof(node));

            // and check if the current node not equals NULL
            if (currentNode != NULL) // if not
            {
                // we save our hash of temp word index to our hashIndex
                hashIndex = hash(tempWord);

                // then copy our temp word to our currentNode before freeng it
                strcpy(currentNode->word, tempWord);

                // assign value from our hash table of its hash index to next pointer in current node
                currentNode->next = hashTable[hashIndex];

                // and assigning value of our current node at its index to hash table
                hashTable[hashIndex] = currentNode;

                // freeing memory for current node
                // free(currentNode);

                numWordsDic++; // and increment our words counter
            }
        }
        fclose(ptrDic); // don't forget to close file
    }
    else
    {
        return false; // if file not opened
    }
    return true; // and return true when all process is done
}

// this is gonna return us a number of words in dictionary if loaded
unsigned int size(void)
{
    return numWordsDic; // dictionary words counter for our `bool load`
}

// and here we gonna `unload` dictionary from memory
// returning true if successful, and false if not succesful
bool unload(void)
{
    // we gonna iterate through our hash table (HASH_TABLE_SIZE)
    for (int i = 0; i < HASH_TABLE_SIZE; i++)
    {
        // and create current node to store our data from hashTable
        node *currentNode = hashTable[i]; // copy an adress of i'th element

        while (currentNode)
        {
            // make temp node to swapping values before deleting prewious node
            node *tempNode = currentNode;
            currentNode = currentNode->next; // copying current node to next pointer
            // and safely freeing prefious
            free(tempNode);
        }

        // check if our current node inside of bounds and equals NULL (end of table)
        if (i == HASH_TABLE_SIZE - 1 && currentNode == NULL)
        {
            return true; // work is done
        }
    }
    return false; // base case is dictionary doesn't uploaded
}

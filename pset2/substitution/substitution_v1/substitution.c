#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// KEY word example - vchprzgjntlskfbdqwaxeuymoi

int main(int argc, string argv[])
{
    // check does user write one argument
    if (argc != 2)
    {
        printf("Run this program with a KEY\n");
        return 1;
    }

    // check does user write KEY word with 26 characters
    char *key = argv[1];
    
    if (strlen(key) != 26)
    {
        printf("Run this program with a KEY of 26 characters\n");
        return 1;
    }

    // check does user write only characters in KEY word
    bool valid = false;
    int lenK = strlen(key);
    
    for (int i = 0; i < lenK; i++)
    {
        if (!isalpha(key[i]))
        {
            printf("KEY word may have contain characters ONLY!\n");
            return 1;
        }
        
        for (int j = i + 1; j < lenK + 1; j++)
        {
            if (tolower(key[i]) != tolower(key[j]))
            {
                valid = true;
            }
            else
            {
                printf("KEY must not contain DUPLICATES!\n");
                return 1;
            }
        }
    }
    
    // ask user for some text to encrypt
    char text[500];
    printf("plaintext: ");
    fgets(text, sizeof(text), stdin);
    printf("\n");


    // cipher text processing
    int lenT = strlen(text);
    
    for (int i = 0; i < lenT; i++)
    {
        if (islower(text[i]))
        {
            text[i] = tolower(key[text[i] - 97]);
        }
        else if (isupper(text[i]))
        {
            text[i] = toupper(key[text[i] - 65]);
        }
    }
    
    // output cipher text result
    printf("ciphertext: %s", text);
    printf("\n");

    return 0;
}
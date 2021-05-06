#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

// KEY word example - vchprzgjntlskfbdqwaxeuymoi

int main(int argc, char *argv[])
{
    char *key = argv[1];
    // validation if the argument exists and contains 26 characters
    if (argc == 2 || strlen(key) == 26)
    {
        // validate alphabetical only KEY

        bool valid = false;
        int lenK = strlen(key);

        for (int i = 0; i < lenK; i++)
        {
            for (int j = i + 1; j < lenK +1; j++)
            {
                if (!isalpha(key[i]) && tolower(key[i]) != tolower(key[j]))
                {
                    valid = true;
                }
                else
                {
                    printf("KEY must contain letters only and not DUPLICATES\n");
                    return 1;
                }
            }
        }

        // ask user for text to encrypt
        char text[500];
        printf("plaintext: ");
        fgets(text, sizeof(text), stdin);
        printf("\n");

        // cipher text
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

        // output encrypted text
        printf("ciphertext: %s\n", text);

        return 0;
    }
    else
    {
        printf("run the program with a KEY of 26 letters\n");
        return 1;
    }
}
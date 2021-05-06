#include <stdio.h>
#include <cs50.h>

int height;
int stop = 0; // its gonna help us to reset spaces counter in out loop

int main(void)
{
    do // Ask user for height fron 1 to 8
    {
        height = get_int("Give me height from 1 to 8: ");
    }
    while (height < 1 || height > 8);

    // Build our piramire from top to bottom
    // At the beginning we have at least 1 hash to print
    // At the start we have spaces = height - 1 to print
    // each loop we have to decrease spaces and repeat process untill spaces = 0
    // then print hashes
    // so what we have:
    // 1. if spaces <= i print hash
    // 2. else if spaces > i and stop = 0
    // 3. if spaces <=0 and stop = 0 here where all magic begins
    // 4. Print "  ",  change stop = 1, and make spaces = height
    // (and since this time none of steps from 1 to 3 is going to proceed)
    // (but space counter if main for loop will be decreasing space counter intil...)
    // (space meet first if (space <= i) in loop and starts printing hashes again from step 1)

    for (int i = 0; i < height; i++)
    {
        for (int spaces = height; spaces >= 0; spaces --)
        {
            if (spaces <= i)
            {
                printf("#");
            }
            else if (spaces > i && stop == 0)
            {
                printf(" ");
            }

            // stops whole process untill spaces counter reset
            if (spaces <= 0 && stop == 0)
            {
                printf("  ");
                stop = 1;
                spaces = height;
            }
        }
        stop = 0;
        printf("\n");
    }
}
#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;

    // 1. Ask user for height from 1 to 8
    //      1.1 If user gives number from 1 to 8 - done
    //      1.2 If user gives number out of prompt - do step 1
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    // initialize hash starting quantity
    int hash = 1;

    // initialize space starting quantity
    int space = height - 1;


    // 1. first we check how much spaces we have to print in terms of height
    // 2. print hashes
    // 3. print two spaces
    // 4. print hashes
    // 5. back to step 1
    for (int n = 0; n < height; n++)
    {
        for (int a = 0; a < space; a++)
        {
            printf(" ");
        }

        for (int b = 1; b <= hash; b++)
        {
            printf("#");
        }

        printf("  ");

        for (int b = 1; b <= hash; b++)
        {
            printf("#");
        }

        printf("\n");
        space--;
        hash++;
    }
}
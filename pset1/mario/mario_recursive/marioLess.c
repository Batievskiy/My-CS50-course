#include <stdio.h>
#include <cs50.h>

// print less mario pyramid

void draw (int height, int h); // recursive function from week 3 and 4

int main(void)
{
    int height;
    // ask user fo pyramid height from 1 to 8
    do
    {
        height = get_int("pyramid's height from 1 to 8: ");
    }
    while ( height < 1 || height > 8);

    // calling function that draws pyramid
    draw(height, height);
}

void draw(int height, int h)
{
    // this is so called Base Case to stop recursion
    // if height is 0 - dont do anything
    if (height == 0)
    {
        return;
    }

    // recursive way to draw pyramid
    // it say - draw at least one row if height is greater than 0
    draw(height - 1, h);

    for (int i = 0; i < h - height; i++)
    {
        printf(" ");
    }

    for (int i = 0; i < height; i++)
    {
        printf("#");
    }
    printf("\n");
}
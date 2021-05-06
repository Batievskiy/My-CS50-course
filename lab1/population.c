#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Determine how long it takes for a population to reach a particular size

    // 1. Ask user for start size of population (greater than 8)
    //      1.1 If start size is less than 8 - repeat step 1.
    //      1.2 If start size more than 8 - done
    int startSize;
    do
    {
        startSize = get_int("Start size \n");
    }
    while (startSize < 9);
    
    // 2. Ask user for end size of population
    //      1.1 If end size less that start size - repeat step 1.
    //      1.2 If end size more than start size - done
    int endSize;
    do
    {
        endSize = get_int("End size  \n");
    }
    while (endSize < startSize);
    
    // 3. Calculate number of years untill population reach end size or more (threshold)
    //      Starting population = startSize
    //      Population grow = population / 3
    //      Pupulation die = population / 4
    //      Population gain by year = population + grow - die

    int grow;
    int die;
    int years = 0;
    int population = startSize;
    
    while (population < endSize)
    {
        grow = population / 3;
        die = population / 4;
        population = population + grow - die;
        years++;
    }
    
    // Print number of years
    printf("Years: %i\n",  years);
    
}
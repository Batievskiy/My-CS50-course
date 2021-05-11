#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    /*

    how to compare strings? easy.)

    */

    char *s = get_string("s: ");
    char *t = get_string("t: ");
    printf("\n");

    // s and t is gonna be different. why? because we compare its adresses
    if (s == t)
    {
        printf("s and t (adresses) is same\n"); // but its not
    }
    else
    {
        printf("s and t (adresses) is different\n");
    }

    if (*s == *t) // here we compare s and t values at their adresses using *s and *t pointers
    {
        printf("s and t (values) is same\n");
    }
    else
    {
        printf("s and t (values) is different\n");
    }
    printf("\n");

    // lets compare characters with strcmp and print some adresses

    char *i = get_string("i: ");
    char *j = get_string("j: ");
    printf("\n");

    printf("adress i: %p\n value i: %s\n", i, i);
    printf("adress j: %p\n value j: %s\n", j, j);
    printf("\n");

    if (strcmp(i, j) == 0) // strcmp - compare two strings
    {
        printf("i and j (values) is same\n");
    }
    else
    {
        printf("i and j (values) is different\n");
    }
    printf("\n");
}


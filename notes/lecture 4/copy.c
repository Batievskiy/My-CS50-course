#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(void)
{
    /*

    how to copy characters? lets see:

    */

    char *s = get_string("s: ");

    // here we allocate chunk of memory size of lenght of s + 1 for s[\0] ending
    char *t = malloc(strlen(s) + 1);


    // this is an ERROR checking
    // if computer is out of memory, malloc eturn NULL
    if (t == NULL) // absence of an adress - adress 0
    {
        printf("Out of memory\n");
        return 1; // error end exit from program
    }

    // hard way to copy all chars from i[0] to i[\0]
    for (int i = 0, n = strlen(s); i <= n; i++) // strlen - calculate the length of a string
    {
        t[i] = s[i]; // show off *(t+i) = *(s+i);
    }

    strcpy(t, s); // easy way to copy all chars from s to t

    if (strlen(t) > 0) // if user didn't typed anything and hit enter
    {
        t[0] = toupper(t[0]); // show off *t = toupper(*t); // capitalize first char t[0]
    }

    printf("s: %s\n", s);
    printf("t: %s\n", t);

    // we have to return that temrorary memory for computer by using free();
    free(t);

    /*

    valgrind - if something wrong with memory we can check that
    just run a program with valgrind ./program

    */

    char *c = malloc(3); // allocate chunk of memory 3 bytes

    // manually filling values to array of chars
    s[0] = 'h';
    s[1] = 'i';
    s[2] = '!';
    s[3] = '\0'; // end of a string
    printf("%s\n", c);

    free(c); // free memory at the end
    // because we dont want 3 bytes in 1 blocks are definitely lost

    /*

    what is Garbage values? everything we didn't use

    */

    int *x; // pointer x with adress pointing to nowhere
    int *y; // pointer y with adress pointing to nowhere

    // we allocate memory size of integer type (4 bytes)
    x = malloc(sizeof(int));

    /*

    and since now pointer *x adress is pointing to x value
    in memory allocated with malloc
    but *y still pointing to nowhere - and that is GARBAGE value

    */

}
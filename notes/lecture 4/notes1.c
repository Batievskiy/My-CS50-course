#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    /*

    Hexadecimal
    - counting system used for adresses for variables in memory
    it has base of 16:
    0 1 2 3 4 5 6 7 8 9 A B C D E F
    0x - is a mark that number in Hexadecimal counting system
    where
    0x1 = 0
    ...
    0x0F = 16
    0x10 = 17
    0x11 = 18
    ...
    0xFF = 255

    RGB HEX code:
    R = 0x FF 00 00
    G = 0x 00 FF 00
    B = 0x 00 00 FF

    */
    /*

    Adresses

    int n = 50; // we created integer and it takes 4 bytes in memory

    in C we can access to the adress of variable with the & operator
    it means - get adress of this variable
    printf("%p\n", &n); // %p print adress of n
    printf("%i\n", *&n); // go to adress and print valuable

    */
    /*

    Pointers

    1. pointer tend to take up 8 bytes
    2. pointer is a variable
    3. pointer store adress of some variable

    int n = 50;
    int *p = &n; // pointer that store adress to n variable
    printf("%p\n", p); // print adress of n ~0x7fff6c53b1cc
    printf("%i\n", *p); // print value at this adress


    Pointers for strings is a different!

    what is string? its array of chars
    string s = "hi!"
    printf("%s\n", s) // print that string s

    typedef char *string - can create new data type name of "string"

    char *s = "hi!"; // it's way of making arrays of chars (strings)

    char *s = "hi!"; // adress to array of characters starting with s[0] to ... s[n]

    s[0] = 'h'
    s[1] = 'i'
    s[2] = '!'
    s[3] = '\0' // end of a string

    for (int i = 0; s[i] != '\0'; i++)
    {
        printf("%c", s[i]); // print all chars in array s[]
    }
    printf("\n");

    printf("%c\n", *s); // print char at the adress of s
    *s goes to the adress stored in s
    // also this is first char s[0] adress

    printf("%c\n", *(s + 1)); // print char at the adress of s[1]
    printf("%c\n", *(s + 2));
    printf("%c\n", *(s + 3)); // end of an array

    printf("%p %c\n", &s[0], s[0]); // print the adress of s[0] and its value
    printf("%p %c\n", &s[1], s[1]);
    printf("%p %c\n", &s[2], s[2]);

    */

}


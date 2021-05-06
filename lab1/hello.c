#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // asking user for a name
    string name = get_string("what is your name?\n");
    
    // telling hello to user with his name
    printf("hello, %s\n", name);
}
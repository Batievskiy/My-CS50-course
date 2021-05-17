#include <stdio.h>
#include <stdlib.h>

// how to use Linked Lists? lecture 5
// this is my explanation for Dummies in programing like me.)

// here we declare(create) a structure that contains:
typedef struct node
{
    int number; //integer for numbers variables
    struct node *next; // pointer for storing adress on next Linked List enement
}
node; // its name

int main(void)
{
    // let's create an empty Linked List
    // and initialize it to NULL (because it could point at garbage value and its bad)
    node *list = NULL; // to prevent of segmentation faults

    // now we allocate some space in a memory
    node *n = malloc(sizeof(node)); // size of node (int(4 bytes) + pointer(8 bytes))

    // don't forget to check does such chunk of memory exist
    if (n == NULL)
    {
        return 1; // error - not enough memory
    }

    n->number = 1; // here we go into 'n' node and into its 'number' field and assign it to 1
    n->next = NULL; // and go into 'n' node and into its 'next' field and assign it to NULL;

    // so just now we allcated one node with struct of 'node'
    // and its number value = 1 and pointer to next = NULL

    // now we update list itself to point at that value
    list = n; // adress of actual node


    // now we want add number two to node as well
    // we allocate 'n' using malloc giving it size of node
    n = malloc(sizeof(node));
    // again check for enough memory
    if (n == NULL)
    {
        free(list); // let's free memory that been allocated to list
        return 1;
    }

    // and if all goes well
    n->number = 2; // we go to new node 'n' and store number 2 into it
    n->next = NULL; // and assign 'next' pointer as NULL

    // and if we want to put this number to node after the number one node
    // we can start at the top of the list go to the next node
    // and inside of its value we can say 'n'
    list->next = n; // starts a the list, follows the arrow and update the next pointer of that first node

    // and lastly let's add one more node
    n = malloc(sizeof(node));
    if (n == NULL)
    {
        free(list->next); // we have to free all the memory we allocater
        free(list);
        return 1;
    }

    n->number = 3; // and update 'number' field to be 3
    n->next = NULL;  // update 'next' field to be NULL
    list->next->next = n; // update the list next to next block to n

    /* and here after we gonna print all this nodes with a for loop
    1. give me a temporaty pointer to a node called *tpm
    2. and initialize it to be whatever at the beginning of the list
    3. keep doing the following so long as tpm does not equals NULL (end of the list)
    4. and on each iteration of this loop - update my 'tmp' pointer
       to be whatever the value of the 'tmp' pinter 'next' field is
    */
    for (node *tmp = list; tmp != NULL; tmp = tmp->next)
    {
        printf("%i\n", tmp->number); // print out watever value is in the 'number' field of that node there
    }

    // and this is a common way of freeing Linked List
    while (list != NULL) // check the beginning of the list is not NULL
    {
        node *tmp = list->next; // get a '*tmp' pointer to the 'next' node in the list
        free(list); // free this current node itself
        list = tmp; // and then update list to be tmp (next node);
        // in a simple way it looks like gobbling up the current node and go to the next one at the list
        // ᗧ . . . . . . . . (. is every next node)
    }
}
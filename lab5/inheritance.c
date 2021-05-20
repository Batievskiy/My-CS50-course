#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h> // for using function `time()` - get time in seconds

// here we gonna create simulator of genetic inheritance of blood type

// this is detailed explanation for beginners in programing like me._)

// here we created structure of `person`
// where each person has two parents and two alleles (OO, OA, OB, AO, AA, AB, BO, BA)
typedef struct person
{
    struct person *parents[2]; // array of two parents
    char alleles[2]; // names of two alleles
}
person; // name of this struct

const int GENERATIONS = 3; // here we create three generations of persons
const int INDENT_LENGTH = 4; // and indentation of generations for printing out

person *create_family(int generations); // this is prototype of function that gonna create family (parents and child)
void print_family(person *p, int generation); // this function is gonna print family members using indentation value
void free_family(person *p); // this function is gonna clear values in current person struct
char random_allele(); // this function is gonna produce random alleles pairs for parents

int main(void)
{
    // here we have a seed random number generator
    // using srand() - seed pseudorandom number generation / time() - get time in seconds
    srand(time(0));

    // here we created a pointer to a new family with three generations
    person *p = create_family(GENERATIONS);

    // this function will print out family tree of blood types
    print_family(p, 0);

    // and here we freeing memory of current persons family struct
    free_family(p);
}

// let's create a new individual(person) with `genetations`
person *create_family(int generations)
{
    // let's go and first of all allocate memory for current person
    // this will create menory for this person in HEAP
    person *p = malloc(sizeof(person)); // *p is a pointer to chunk of memory

    // now we can check our current generation with parents data
    if (generations > 1) // check if generation exist
    {
        // and now we recursively create blood type histories for parents in three generations
        // in other words - recursively call `create_family()` function on each of the parents
        // *p is the pointer which give us the access to parents arrays
        p->parents[0] = create_family(generations - 1); // this is first parent
        p->parents[1] = create_family(generations - 1); // and second parent
        // so... we just creater family ;) for zero-th person

        // now what we have to do?
        // correct - we randomly assigh a child alleles based on parents
        // to do that we can use simple `modulo` operator %2 - and grab the remainer (0 or 1)
        // and use it like an indexes for alleles
        int randIndex0 = rand() % 2; // this ramdomly give us 0 or 1
        p->alleles[0] = p->parents[0]->alleles[randIndex0]; // assign to first allele

        int randIndex1 = rand() % 2;
        p->alleles[1] = p->parents[1]->alleles[randIndex1]; // and assigh second allele
    }

    // and proceed a generation without parents data
    else
    {
        // here we set parent pointers to null
        p->parents[0] = NULL;
        p->parents[1] = NULL;

        // here we randomly assigh alleles
        p->alleles[0] = random_allele();
        p->alleles[1] = random_allele();
    }

    // after all this we return newely created person and its full data for parents
    return p;
}

// here we have to free person `p` and all his ancestors
void free_family(person *p)
{
    // dont forger to check if `p` that we received from createFamily is NULL
    if (p == NULL)
    {
        return; // return nothing back
    }

    // here we freeing particular parent of current person before we are freeing thi child
    // becase once we freed the child - we no longer have access to the parents
    // so.. sequence is matters
    free_family(p->parents[0]);
    free_family(p->parents[1]);

    // and only after that we can free current child
    free(p);
}

// here we print each family member and their alleles
void print_family(person *p, int generation)
{
    // check a base case when p pointing to nothing
    if (p == NULL)
    {
        return;
    }

    // and print indentations
    for (int indent = 0; indent < generation * INDENT_LENGTH; indent++)
    {
        printf(" ");
    }

    // and now we print person
    printf("Generation %i, blood type %c%c\n", generation, p->alleles[0], p->alleles[1]);
    print_family(p->parents[0], generation + 1);
    print_family(p->parents[1], generation + 1);
}

// this one is gonna give us random blood type alleles
char random_allele()
{
    int rnd = rand() % 3; // this `modulo` operator give us three numbers (0, 1 or something else)
    if (rnd == 0)
    {
        return 'A';
    }
    else if (rnd == 1)
    {
        return 'B';
    }
    else
    {
        return 'O';
    }
}
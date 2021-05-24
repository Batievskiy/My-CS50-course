#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

// out hash table is gonna store information about people
#define MAX_NAME 256
#define TABLE_SIZE 10

// any pointer that has this value we know it's been deleted
#define DELETED_NODE (person*)(0xFULL)
/* this allow us to determine when we can stop searching free place in the table
 * so if we find a deleted node, we have to keep looking
 * but if we find one that's null than we can stop
 * because we know the node we're looking for can't be beyond that point
*/

typedef struct {
    char name[MAX_NAME];
    int age;
    // some other info...
} person;

// this is gonna be an array of pointers to people structs
person *hashTable[TABLE_SIZE];

// this is our hash function
// we gonna look for names of people
unsigned int hash(char *name) {
    int length = strlen(name);
    unsigned int hashValue = 0;
    for (int i = 0; i < length; i++) {
        hashValue += name[i];
        hashValue = (hashValue * name[i]) % TABLE_SIZE; // use `modulo` operatir to make hash numbers smaller
    }
    return hashValue;
}

// let's make a function thats goint to set up a table
void initHashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = NULL;
    }
    // table is empty for now
}

// let's make a function that prints out the status of the table
void printTable() {
    // let's print start marker
    printf("start\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i] == NULL) {
            printf("\t%i\t---\n", i);
        } else if (hashTable[i] == DELETED_NODE) { // check to see if it's been deleted node

            printf("\t%i\t---<deleted>\n", i);
        } else {
            printf("\t%i\t%s\n", i, hashTable[i]->name); // if not just print the name
        }
    }
    printf("end\n");
}

/* at last let's deal with collisions

 * when collisions occur there are two traditional ways that we can handle this
 * one is called `open adressing`
 * and other called `external chaining`

 * with `open adressing` we're gonna keep eerything in the table
 * if the first location the hash function gives us is full we need to look for another
 * and this can be done by either using the hash function again
 * to try to find another location in the table
 * and there are different ways to do that

 * the SIMPLEST WAY to solve this is called `linear probing`
 * with this we start at the hash location and then if that's taken
 * we don't call the hash function again we just check the next location in the table
 * and the next and the next until we find one that's available
 * or maybe we go through the entire table and eventually we get back to where we started
 * and realize that the table is full and at that point we really can't add anything
 * so we're just done (sorry the table is full.)

 see the code in bool hashTableInsert down below
 (don't forget to add this logic to lookup and delete function as well)
*/

// let's make a function that gonna insert person into the table
// this function will return a true if person succesfully added a person
bool hashTableInsert(person *p) {
    if (p == NULL) return false;

    // let's compute the hash function of the persons name
    // and this is going to be an index of the place where we are going to try to put the person
    int index = hash(p->name);

    // dealing with a collisions
    // we need to update insert, so we actually do need to add a loop
    for (int i = 0; i < TABLE_SIZE; i++) {

        // and we are going to start at our hash location
        int trY = (i + index) % TABLE_SIZE;

        // and then we're gonna go until fe find an open space in the table
        if (hashTable[trY] == NULL ||
            hashTable[trY] == DELETED_NODE) { // if we find a pointer that is null of deleted
            hashTable[trY] = p; // we use it
            return true;
        }
    }
    // if we go through the entire array and don't find flee place
    // then we're out of luck so return null
    return false;
}

// look up function with one argument `name` (find a person in the table by its name)
// it returns null if the person is not in the table
// and it returns a pointer to the person if it is in the table
person *hashTableLookup (char*name) {

    // lets compute our hash
    int index = hash(name);

    // we're going to start at the location the hash function gave us
    for (int i = 0; i < TABLE_SIZE; i++) {

        // and then just keep looking to see if we can find a match
        int trY = (index + i) % TABLE_SIZE;
        // we're going to look at the location in the table

        // we want to bail if we find a null pointer
        if (hashTable[trY] == NULL) return false; // not here

        // and if we find a deleted node, just continue on to the next iteration
        if (hashTable[trY] == DELETED_NODE) continue;

        // and if it's not null of deleted we check to see if the names match
        if (strncmp(hashTable[trY]->name, name, TABLE_SIZE) == 0) {
            return hashTable[trY]; // person actually in the table
        }
    }
    // otherwise we're going to return null
    return NULL;
}

// for completeness let's make a delete function
// in delete we do the same as in lookup exept we delete the person
// and return a pointer to the struct
person *hashTableDelete(char *name) { // its actually lot like insert exept that we want to remove the person
    int index = hash(name);

    // we're going to start at the location the hash function gave us
    for (int i = 0; i < TABLE_SIZE; i++) {
        int trY = (index + i) % TABLE_SIZE;

        // return if the node is null
        if (hashTable[trY] == NULL) return NULL;

        // keep searching if it's deleted
        if (hashTable[trY] == DELETED_NODE) continue;

        // and delete it otherwise
        if (strncmp(hashTable[trY]->name, name, TABLE_SIZE) == 0) {

            person *tmp = hashTable[trY]; // we find location and save a pointer to it
            /* here we want to remove the person
             * but instead of setting deeted nodes back to null
             * we're gonna use a value like null that
             * we know will never be a valid adress `DELETED_NULL`
             * any pointer that has this value we know it's been deleted
            */
            hashTable[trY] = DELETED_NODE; // then we remove it from the table
            return tmp;// then return a pointer that we saved to the caller
        }
    }
    return NULL;
}

/* at last let's deal with collisions

 * when collisions occur there are two traditional ways that we can handle this
 * one is called `open adressing`
 * and other called `external chaining`

 * with `open adressing` we're gonna keep eerything in the table
 * if the first location the hash function gives us is full we need to look for another
 * and this can be done by either using the hash function again
 * to try to find another location in the table
 * and there are different ways to do that

 * the SIMPLEST WAY to solve this is called `linear probing`

 * with this we start at the hash location and then if that's taken
 * we don't call the hash function again we just check the next location in the table
 * and the next and the next until we find one that's available
 * or maybe we go through the entire table and eventually we get back to where we started
 * and realize that the table is full and at that point we really can't add anything
 * so we're just done (sorry the table is full.)
*/

int main() {

    initHashTable();
    printTable();

    // let's make some people
    person jacob = {.name="Jacob", .age=25};
    person kate = {.name="Kate", .age=27};
    person murphy = {.name="Murphy", .age=21};
    person amily = {.name="Amily", .age=23};
    person sarah = {.name="Sarah", .age=28};
    person robert = {.name="Robert", .age=24};
    person jackie = {.name="Jackie", .age=26};
    person peter = {.name="Peter", .age=29};
    person diana = {.name="Diana", .age=22};
    person nikola = {.name="Nikola", .age=20};

    // let's add them all to the hash table
    hashTableInsert(&jacob);
    hashTableInsert(&kate);
    hashTableInsert(&murphy);
    hashTableInsert(&amily);
    hashTableInsert(&sarah);
    hashTableInsert(&robert);
    hashTableInsert(&jackie);
    hashTableInsert(&peter);
    hashTableInsert(&diana);
    hashTableInsert(&nikola);

    // let's try look up a name that is in there
    person *tmp = hashTableLookup("Jacob");

    if (tmp == NULL) { // we can print out wether of not we found he
        printf("Not found! %s\n", tmp->name);
    } else {
        printf("Found %s.\n", tmp->name);
    }

    // next we do the same thing with the name that we know is not in there
    tmp = hashTableLookup("Kyle");

    if (tmp == NULL) { // we can print out wether of not we found he
        printf("Not found! %s\n", tmp->name);
    } else {
        printf("Found %s.\n", tmp->name);
    }

    // let's delete some person
    hashTableDelete("Murphy");

    // and then check to make sure he is no longer in the table
    tmp = hashTableLookup("Murphy");
    if (tmp == NULL) {
        printf("Not found! %s\n", tmp->name);
    } else {
        printf("Found %s.\n", tmp->name);
    }

    // and let's again print out the table for good measure
    // to see that he is no longer there
    printTable();

    return 0;
}

/* and now we are able to add all of our people
 * and we can also see where the one person was that we deleted

 * what nice about this approach?
 * with open adressing the tableis always the same size
 * once it's full it's full
 * that can be a good thing or a bad thing
 * depending on how we want our system to fail
 * if we are in a scenario where have hard limits
 * on how much memory we can use
 * that this can be a good thing

 * but what is bad about this approach?
 * as our table fills up - all benefits of fast hash tables
 * they all disappear because as the table fills up
 * we're gonna do more and more searching for free space
 * and our table is gonna get quite slow
 * and if we do a lot of insetrions and lot of deletions
 * over time eveltially all of our empty slots
 * are all gonna be marked as deleted
 * that little optimization that we did by marking tham as deleted
 * isn't actually gonna benefit us much anyway
 * and overall performance could get really terrible

 * of course we can add some code and
 * try to clean up those deleted markers when they're no longer needed
 * but that's a pain.)

 * also if our hach function isn't very random then linear probing
 * can also produce big clusters of objects
 * so even if the table is not full
 * we can have problems where our performance still gets realy bad

 * in responce to this are other options
 * like quadratic probing and double hashing
 * that people use to avoid clustering
 * and they come up with their own issues and complications

 * bur for now we are going to leave it like this
 * and try another approach in another file.)
 * see you at the next hashtableV2.c
*/


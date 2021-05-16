#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// this is detailed explanation for Dummies in programming like me :)
// check my short plan to solve this problem in - pseudocode - file (same folder here)

typedef unsigned char JPG; // this is our 1 byte chunk for checking the header of jpgs
#define CHUNK_SIZE 512 // this is 512 byte chunks to read and write files
#define NAME_SIZE 8 // this is 8 byte size of filename to store 000.jpg format

bool isStartNewJpg(JPG buffer[]); // check for the start of a first jpg

int main(int argc, char *argv[])
{
    // let's check for proper arguments here
    if (argc != 2)
    {
        printf("usage: ./recover image\n");
        return 1;
    }

    // next we gonna open our file in read mode
    // and use file name from argv[1]
    FILE *inputFile = fopen(argv[1], "r");

    // then we have to check is this file exist
    if (inputFile == NULL)
    {
        printf("such file does not exist!\n");
        return 1; // error - because such file does not exist
    }

    // and now we gonna define a buffer size of 512 bytes
    JPG buffer[CHUNK_SIZE];
    // we can also create a pointer to a buffer using malloc, like this:
    // JPG *buffer = malloc(CHUNK_SIZE);

    bool isFoundFirstJpg = false; // we gonna create check function to find first jpg

    // than we have to read the file into buffer
    FILE *outputFile;
    int fileCounter = 0; // file counter
    while (fread(buffer, CHUNK_SIZE, 1, inputFile)) // read one 512 byte chunk at the time
    {
        if (isStartNewJpg(buffer)) // if we have found start of a new jpg
        {
            // we must check if is that first jpg
            if (!isFoundFirstJpg)
            {
                isFoundFirstJpg = true;
            }
            else // we must close previous file
            {
                fclose(outputFile);
            }

            // and then we create a new file
            char filename[NAME_SIZE];
            // we can also create a pointer to a new file using malloc, like this:
            // char *filename = malloc(FILE_NAME_SIZE);

            // and gonna to represent this file format
            sprintf(filename, "%03i.jpg", fileCounter++); // and count how many files I've found

            // after that we gonna open file with write mode to save there
            outputFile = fopen(filename, "w");

            // of cource don't forget to check is file exist
            if (outputFile == NULL)
            {
                printf("file not found!");
                return 1; // error - because such file does not exist
            }

            // after that when we successfully opened the file
            // we gonna write from buffer 512 bytes to outfile
            fwrite(buffer, CHUNK_SIZE, 1, outputFile);
        }
        else if (isFoundFirstJpg) // if we have found first jpg and red it
        {
            // we must keep on writing the previous file
            fwrite(buffer, CHUNK_SIZE, 1, outputFile);
        }
    }
    // after finishing with this files
    // we have to close it
    fclose(outputFile);
    fclose(inputFile);

    // free(buffer); // if using malloc
    // free(filename);

    printf("files recovered: %i\n", fileCounter); // print the number of files counted
}

// here we gonna check for the start of a first jpg
bool isStartNewJpg(JPG buffer[])
{
    /* here we check first three bytes: 0xff 0xd8 0xff
    * and using bitwise arithmetic
    * just look at the frst four bits of this 8 bite
    * and set the remaining four bits to 0
    * (buffer[3] & 0xf0) == 0xe0
    * and return true if all conditions are passed
    */
    return buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0;
}

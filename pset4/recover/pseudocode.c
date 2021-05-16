#include <stdio.h>

int main(int argc, char *argv[])
{
    /*
    * this is our short plan to solve this problem:

    * each jpeg starts with a distinct header:
        * first three bytes: 0xff 0xd8 0xff
        * last byte is: 0xe0, 0xe1, 0xe2, ..., 0xef
    * jpegs stored back-to-back in memory card
    * each block is 512 bytes

    read files:
    * fread(data, size, number, inptr);
    * data - pointer to where to store data you're reading
    * size - size of each element to read
    * number - number of elements to read
    * inptr - FILE * to read from
    in 512 byte chunks

    check for:
    buffer[0] == 0xff
    ...
    buffer[3] == 0xe0 ... 0xef // here we have use boolien

    bitwise arithmetic
    - just look at the frst four bits of this 8 bite
    - and set the remaining four bits to 0
    (buffer[3] & 0xf0) == 0xe0

    making a new jpeg
    * filenames: starting at 000.jpg
    * we have to keep track of how many jpeg files we found
    * to write correct file names

    how to make a string for that?
    * printing to a string:
    * sprintf(filename, "%03i.jpg", 2);
    * filename - name of the string
    * "%03i.jpg" - format string that print integer with three digits
    * that represented numbers like 000 ... 999
    * 2 - number we want to substitute
    * make sure that file name has enough characters
    * to fully represent this entire filename

    after we created filename:
    * we can open a new file with tnat filename
    FILE *imp = fopen(filename, "w") // write mod

    writing files:
    * fwrite(data, size, number, outptr);
    * data - pointer to bytes that will be written to file
    * size - size of each element to write
    * number - number of elements to write
    * inptr - FILE * to write to

    pseudocode:

    open memory card
    repeat until end of card:
        read 512 bytes into buffer
        if start of new jpeg
            if first jpeg
            ... start writing 000.jpeg
            else
            ... close jpeg
        else
            if already found jpeg
            ... keep writing to next 512 byte bloc
            ... repeat
    close amy remaining files
    */
}
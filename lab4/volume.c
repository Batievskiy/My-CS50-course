#include <stdio.h> // for using fread, fwrite, fopen, fclose functions
#include <stdlib.h> // atof - convert a string to a float
#include <stdint.h> // for using uint8_t and int16_t - by the way this hasn't been told on the lecture

// This is my explanation of each line of code here for Dummies like Me.)

// here we wand to modify input.wav volume
// by multiplying each byte of the file to factor
// (2.0 - doubles the volume)
// (0.5 - cuts the volume in half)

// this is represents number of bytes in input.wav file header
// it takes first 44 bytes of the file
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    /* here we check users input for all 4 command line arguments
    1st is ./volume - program itself
    2nd is input.wav - the file that we gonna interact with
    3rd is output.wav - the file that we gonna recreate from input.wav with changed volume
    4th is factor (2.0 or 0.5) - multiplier of volume
    */
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1; // error - because of incorrect argument quantity
    }

    // here we gonna open input.wav file and determine scaling factor (2.0 of 0.5)
    // we created pointer *input that points to function fopen
    // that opens file from argument argv[1] (input.wav)
    // in "r" mod - opening the file in order to read from it,
    FILE *input = fopen(argv[1], "r");

    // than we always have to check is that file exist
    // we have to check does fopen return FILE pointer if file exist
    // or return NULL if file doesn't exist
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1; // error - because file doesn't exist
    }

    // here we gonna open file from argv[2] - output.wav file
    // in "w" mod - opening the file in order to write to it
    FILE *output = fopen(argv[2], "w");

    // and check is fopen() return NULL if file doesn't exist
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1; // error - because output.wav doesn't exist
    }

    // here we compute the factor
    // converting that factor fron argv[3] to a floating point number
    // atof - convert a string to a float
    float factor = atof(argv[3]);

    // here we copy header fron input file to output file
    // uint8_t - is data type with fixed 8 bit size positive integer
    // best choice for header that contains 44 bytes
    // this is created an array size of header from input.wav
    uint8_t header[HEADER_SIZE]; // we gonna store header from input file to this array

    // this function reads data from the file that has been opened via fopen function - input.wav
    // explain from right to left:
    // input - the address of the first byte of memory into which to read the data
    // 1 - the size in bytes of the type of data to read
    // HEADER_SIZE - the number of those types to read at once (44 bytes)
    // header - the pointer to a FILE returned by fopen
    fread(header, HEADER_SIZE, 1, input); // here we read all bytes of header from input file

    // this function write data to the file that has been opened via fwrite function - output.wav
    fwrite(header, HEADER_SIZE, 1, output); // here we write all bytes to header in output file

    // here we read samples from input.wav
    // proceed with each 2 bytes by multiplying each to factor
    // int16_t - is data type with fixed 16 bit size integer
    // best choce for 2 byte samples from WAV format
    int16_t temp_buffer;

    while (fread(&temp_buffer, sizeof(int16_t), 1, input))
    {
        temp_buffer *= factor;
        fwrite(&temp_buffer, sizeof(int16_t), 1, output);
    }

    // after we done with copying and writing files we have to close them all
    // this function closes a file that has been opened via fopen
    // it expects as input the pointer to a FILE that was returned by fopen
    fclose(input);
    fclose(output);
    return 0;
}

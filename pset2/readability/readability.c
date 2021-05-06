#include <stdio.h>
#include <cs50.h> // get_string - prompt a user for a string
#include <string.h> // strlen - calculate the length of a string
#include <ctype.h> // isalpha - check whether a character is alphabetical
#include <math.h> // round - round a number to the nearest integer

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
int c_l_index(int letters, int words, int sentences);
void print_grade(int index);

int main(void)
{
    string text = get_string("Text: ");
    int letters = count_letters(text);
    // printf("Number of letters: %d\n", letters);
    int words = count_words(text);
    // printf("number of words: %d\n", words);
    int sentences = count_sentences(text);
    // printf("number of sentences: %d\n", sentences);
    int index = c_l_index(letters, words, sentences);
    print_grade(index);
}


// let's count letters in string text
// for each i until < length of text
//  1. check is it character?
//  2. if yes count letters + 1
//  3. if no - skip and repeat step 1
// when ends - return counter letters like integer
int count_letters(string text)
{
    int letters = 0;

    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
    }
    return letters;
}

// let's count words in string text
// isspace - check whether a character is whitespace // found this in manual.cs50.io
// for each i until < length of text
//  1. check is it space? - if yes - skip
//  2. else if check is it character? if yes
//      2.1 check is reading word? if true
//          2.1.1 is reading word = true
//          2.1.2 words counter + 1
// when ends - return words counter
int count_words(string text)
{
    bool reading_word = false; // Flag - are the function currently reading a word or not
    int words = 0;

    // let's use oldschool end of string check != '\0'

    for (int i = 1; text[i] != '\0'; i++)
    {
        if (isspace(text[i]))
        {
            reading_word = false;;
        }
        else if (isalpha(text[i]))
        {
            if (!reading_word)
            {
                reading_word = true;
                words++;
            }
        }
    }
    return words;
}

// let's count sentences
// in ASCI '.' = 46; '?' = 63; '!' = 33; - this all END of a sentences
// for each i unti < length of text
// 1. check for character = 46 or 63 or 33
// 2. if yes sentence counter + 1
// return sentence counter

int count_sentences(string text)
{
    int sentences = 0;

    for (int i = 0; text[i] != '\0'; i++)
    {
        int character = text[i];
        if (character == '.' || character == '?' || character == '!')
        {
            sentences++;
        }
    }
    return sentences;
}

// let's count Coleman-Liau index = 0.0588 * L - 0.296 * S - 15.8
// L = letters / (words / 100); S = sentences / (letters / (words / 100))

int c_l_index(int letters, int words, int sentences)
{
    float words_per_100 = words / 100.0;
    float L = letters / words_per_100;
    float S = sentences / words_per_100;
    int index = round(0.0588 * L - 0.296 * S - 15.8);
    return index;
}

// and last function for printing Grade + index
// Before Grade 1 - if index < 1; Grade i if between 1 and 16; Grade 16 - if index >=16+
void print_grade(int index)
{
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", index);
    }
}
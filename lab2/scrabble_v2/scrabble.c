#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

// points assigned to eash letter of alphabet
int points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int get_score(string word);
int get_index(char c);

int main(void)
{
    // get input from players
    string word1 = get_string("player 1 word: ");
    string word2 = get_string("player 2 word: ");

    //score words
    int score1 = get_score(word1);
    int score2 = get_score(word2);

    // winner is gonna be...
    if (score1 > score2)
    {
        printf("player 1 wins\n");
    }
    else if (score2 > score1)
    {
        printf("player 2 wins\n");
    }
    else
    {
        printf("Tie");
    }
}

// this function give us score for each character in word
// at the end of an array of word we have '\0' sign - this is end of array
// lets use '\0' as stop point for our loop; word[i] != '\0';
// you can also use strlen(word) as stop point; (int i = 0, len = strlen(word); i < len;)
// isaplha(c) gives you check does input is char in word[] array
// and then takes index from get_index(char c) function
// compares this index with points[] array
// and adds it point to score
int get_score(string word)
{
    int score = 0;
    for (int i = 0; word[i] != '\0'; i++)
    {
        char c = word[i];

        if (isalpha(c))
        {
            score += points[get_index(c)];
        }
    }
    return score;
}

// fhis function calculates index of characters in words
// char 'a' is 97 in ASCI
// if character in word is A, its function makes it to lowercase a
// and 'a'(97) - 'a'(97) = 0 index in points[] array its first number here {1, ...}
// so 'a' character is gives us 1 point
int get_index(char c)
{
    return tolower(c) - 'a';
}
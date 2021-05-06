#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Print the winner

    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!");
    }
}

// char letter = word[i]; is gonna be in loop for best code readability
// 'A' is 65; so A - A = 0 index in POINTS[] array; {1, ....} A give us 1 point (as example)
// 'a' is 97 same here, but for lowercase
int compute_score(string word)
{
    // score is gonna be store points from POINTS[] array
    int score = 0;

    for (int i = 0, len = strlen(word); i < len; i++)
    {
        char letter = word[i];

        if (isupper(letter))
        {
            score += POINTS[letter - 'A'];
        }
        else if (islower(letter))
        {
            score += POINTS[letter - 'a'];
        }
    }
    return score;
}

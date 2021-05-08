#include <cs50.h>
#include <stdio.h>
#include <string.h> // strcmp - compare two strings - this function returns 0 if s1 is the same as s2;

// This is my explanation of each line of code here for Dummies like Me.)

// this is hardcoded maximum number of candidates
// that user can write like an arguments at the start
#define MAX 9

// this is a collection of variables under a single name
// candidate is gonna include its name and his votes
typedef struct
{
    string name;
    int votes;
}
candidate;

// this is array of candidates with structure of candidate struct (nane and votes)
// its size is MAX that equals 9
candidate candidates[MAX];

// this is number of candidates that is gonna be read from users input as argument
int candidate_count;

// this is future functions prototypes that is gonna be solved later
bool vote(string name);
void print_winner(void);


// here we have main function with integer to store arguments counter and string array to store arguments
int main(int argc, string argv[])
{
    // here we check - does user input arguments?
    // if not - print warning how to use program
    // by default running program has argc = 1 argument with index 0

    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1; // means that is error in program usage and stops program
    }

    // initialize counter of candidates
    // for example: users input contains two names
    // so default argc = 1; 2 and 3 for names (indexes is 0, 1, 2)
    // how much candidates we have? argc = 3 - 1; 2 candidates

    candidate_count = argc - 1;

    // check if candidates counter exceeds MAX 9 array size

    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %d\n", MAX);
        return 2; // means that is error in program usage and stops program
    }

    // here we filling in array candidates[].name and candidates[].votes with names and votes = 0;
    // for that we gonna use index from argv[]
    // for example: we have two names in argv[]; 0 index its for program; index 1 first name; index 2 is second name;
    // so argv[0 + 1] its our first name; and argv[i + 1] its our i'th name in candidates[i].name;
    // for each i until < candidates_count
    // 1. assign name from argv[i + 1] index to i in candidates[].name
    // 2. assign starting 0 votes to i in candidates[].votes

    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    // here we ask user amount of voters and store its value to counter

    int voters_count = get_int("Number of voters: ");

    // here we ask user to vote for candidates if candidates[].name
    // for each i until < voters_count
    // 1. prompt for name input
    // 2. compare name with function bool vote(string name)
    //  2.1 if true - repeate step 1
    //  (if name from input equals to name from candidates[].name, then + 1 to candidate[].votes)
    //  2.2 if false - print Iinvalid vote and repeate step 1
    // when ends - use print winner function

    for (int i = 0; i < voters_count; i++)
    {
        string name = get_string("Vote: ");

        // if not valid vote name from candidates[].name
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // print winner and done.))) that was awesone

    print_winner();

}

// it's purpose to compare each name in array of candidates[].name
// for each i until < candidate_count
// 1. compare name with candidates[i].name
//  1.1 if its equals - return true and increase vote counter by 1
//  1.2 if its not - repeat step 1.1
// 2. when done whole array - return false

bool vote(string name)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i].name) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}

// it's purpose to calculate final votes for each candidate in array candidates[].votes
// and compare it with each other
// we will use max_votes variable to store vote counter from each i in candidates[].votes
// and compare it with max_votes to define the winner
// for each i until < candidate_count
// 1. compare i votes in candidates[].votes with max_votes
//  1.1 if its greater or equals - store this variable in max_votes
// for each i until < candidate_count
// 1. compare i votes in candidates[].votes with max_votex
//  1.1 if its equal - print name in candidates[i].name
// when its done - return;

void print_winner(void)
{
    int max_votes = 0;

    // search for most votes candidate
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes >= max_votes)
        {
            max_votes = candidates[i].votes;
        }
    }

    // compare each i votes in candidates[].votes with max_votes and print winner
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == max_votes)
        {
            printf("%s\n", candidates[i].name);
        }
    }
    return;
}

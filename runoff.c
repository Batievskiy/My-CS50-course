#include <cs50.h>
#include <stdio.h>
#include <string.h> // strcmp - compare two strings - this function returns 0 if s1 is the same as s2;
#include <math.h> // round - round a number to the nearest integer

// This is my explanation of each line of code here for Dummies like Me.)

#define MAX_VOTERS 100 // this is hardcoded number of voters
#define MAX_CANDIDATES 9 // this is hardcodec maximun number of candidates, that user can write as an argument at the start

// this array reproduce each rank for each candidate given from each voter
// for example: we have 4 voters and 3 candidates > preferences[4][3];
// let's count from 1 for easy visualization of two dimentional array.)))
//   voter: [1][2][3][4]
// cand[1]:  2  1  1  3
// cand[2]:  1  2  2  3
// cand[3]:  3  3  3  1
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// this is a collection of variables under a single name 'candidate'
// each candidate do have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;

// Array of candidates size of N = MAX_CANDIDATES;
// for example:3 candidates > candidates[1, 2, 3]
// (we still count from 1 for better visualization.)
candidate candidates[MAX_CANDIDATES];

// this is the number of candidates that is gonna be read from users input as argument when program starts
int candidate_count;
// this is the number of voters that is gonna be read from users input
int voter_count;

// this is future functions prototypes that is gonna be solved later
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

// here we have main function with integer argc to store arguments counter and string argv[] to store arguments (names of candidates)
int main(int argc, string argv[])
{
    // here we check does user input arguments? if not, then print warning how to use program
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1; // means that is error in program usage and stops program
    }

    // this is counter of candidates
    // for example: users input contains two names
    // so default argc = 1; 2 and 3 for names (indexes is 0, 1, 2)
    // how much candidates we have? argc = 3 - 1; 2 candidates
    candidate_count = argc - 1;

    // check if candidates counter exceeds MAX_CANDIDATES array size
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2; // means that is error and stops program
    }

    // here we fill in array candidates[].name, candidates[].votes and candidates[].eliminated
    // with names, votes = 0 and eliminated = false ath the begining
    // for that we gonna use index from argv[]
    // for example: we have two names in arvg[]; [0] is program itself; [1] is first name; [2] is second name;
    // so agrv[i + 1] this is out i'th name in candidates[i].names
    // for each i until < candidate_count
    // 1. assign name from argv[i + i] to candidates[i].name
    // 2. assign starting 0 votes to candidates[i].votes
    // 3. assign starting false statement to candidates[i].eliminated

    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    // here we ask user for input amount of voters and store this value to counter
    voter_count = get_int("Number of voters: ");

    // the number of voters is MAX_VOTERS = 100; so we have to check users input
    // if users amount of voters is greater than MAX_VOTERS
    // 1. print max number of voters restriction
    // 2. terminate program

    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3; // means that is an error and stop program
    }

    // here we ask user for vote from 1 to voters_counter times
    // and for each rank from 1 to candidates_count,
    // here we start count from 0 as we been taught, so:
    // rank = 0 at the start of loop, but we want to print something like this: Rank 1 (not Rank 0)
    // for each voter until < voters_count
    // 1. for each rank until < candidate_count
    //  1.1 ask for name of candidate
    //  compare name with candidates[i].name in bool vote()
    //  if return true - do step 1.1
    //  if return false - print error message and stop program

    for (int voter = 0; voter < voter_count; voter++)
    {
        // ask name for each rank
        for (int rank = 0; rank < candidate_count; rank++)
        {
            string name = get_string("Rank %d: ", rank + 1);

            // store vote inside bool vote(), inless it's invalid
            if (!vote(voter, rank, name))
            {
                printf("Invalid vote.\n");
                return 4; // means that is an error and stop program
            }

        }
        printf("\n");
    }

    // here we proceed runoffs until winner exists
    while (true)
    {
        // calculate voters given remaining candidates
        tabulate();

        // check if election has been won
        bool won = print_winner();
        if (won)
        {
            break; // end of program with winner printed
        }

        // eliminate candidates who is last place
        int min_votes = find_min();
        bool tie = is_tie(min_votes);

        // if tie, everyone wins and print all candidates here
        if (tie)
        {
            for (int candidate = 0; candidate < candidate_count; candidate++)
            {
                if (!candidates[candidate].eliminated)
                {
                    printf("%s\n", candidates[candidate].name);
                }
            }
            break; // end of program with all candidates winners printed
        }

        // eliminate candidates with minimum number of votes
        eliminate(min_votes);

        // reset vote counters back to zero
        for (int candidate = 0; candidate < candidate_count; candidate++)
        {
            candidates[candidate].votes = 0;
        }
    }
    return 0;
}

// here we check each vote name from users input with names in array candidates[].name
// and store ranks from 0 to candidate_count in array preferences[voter][rank] if vote for name is valid
// for each candidate from 0 until < candidate_count
// 1. compare name with candidates[i].name
//  1.1 if its equal - store rank to preferences[voters][rank] and return true
// 2. when end - return false;

bool vote(int voter, int rank, string name)
{
    for (int candidate = 0; candidate < candidate_count; candidate++)
    {
        if (strcmp(name, candidates[candidate].name) == 0)
        {
            preferences[voter][rank] = candidate;
            return true;
        }
    }
    return false;
}

// here we check every preferences in array preferences[voter][rank]
// and if candidate wasn't eliminated in current runoff loop
// we add + 1 to votes for this particuar candidate in candidates[].votes
// we gonna use candidate variable to store index of particular candidate in preferences[voter][rank]
// for each voter from 0 until < voter_count
// 1. check all ranks for each rank from 0 until < candidate_count
//  1.1 take index of current candidate and check if it's been eliminted
//  1.2 add 1 to current candidate[].votes
//  1.3 stop procedure (break from loop)

void tabulate(void)
{
    for (int voter = 0; voter < voter_count; voter++)
    {
        for (int rank = 0; rank < candidate_count; rank++)
        {
            int candidate = preferences[voter][rank];
            if (!candidates[candidate].eliminated)
            {
                candidates[candidate].votes++;
                break;
            }
        }
    }
}

// here we take total number of votes for each candidate in the array candidates[].votes
// candidate wins if it takes more than 50% of votes, so
// we gonna use max_votes to store rounded value of voter_counter / 2
// compare each value in candidates[].votes with max_votes to define winner
// for each candidate from 0 until < candidate_count
// 1. compare votes in candidates[candidate].votes with max_votes
//  1.1 if it's greater - its the winner
//  1.2 return true
// 2. when ends - return false

bool print_winner(void)
{
    for (int candidate = 0; candidate < candidate_count; candidate++)
    {
        int max_votes = round(voter_count / 2);
        if (candidates[candidate].votes > max_votes)
        {
            printf("%s\n", candidates[candidate].name);
            return true;
        }
    }
    return false;
}

// here we calculate the minimum number of votes that any candidate that still in runoff has
// we gonna use min_votes variable to store value from candidates[0].votes to compare with it like a starting value
// and we will use candidate_votes variable to store values from candidates[].votes for each loop iteration
// for each candidate from 1 until < candidate_count
// (we don't need to compare 1st candidate with itself; that's why we start from 1)
// 1. check if candidate_votes < min_votes and candidate isn't eliminated
//  1.1 store candidate_votes in min_votes
// when ends - return min_votes

int find_min(void)
{
    int min_votes = candidates[0].votes;
    for (int candidate = 1; candidate < candidate_count; candidate++)
    {
        int candidate_votes = candidates[candidate].votes;
        if (candidate_votes < min_votes && !candidates[candidate].eliminated)
        {
            min_votes = candidate_votes;
        }
    }
    return min_votes;
}

// here we check for candidates with same value of votes in candidate[].votes and if it's minimum
// and return true if find such candidates has been found, so:
// for each candidate fron 0 until < candidate_count
// 1. check if candidate has not been eliminated? and if its votes not equals min_votes
//  1.1 return false
// 2. otherwise - return true
bool is_tie(int min_votes)
{
    for (int candidate = 0; candidate < candidate_count; candidate++)
    {
        if (!candidates[candidate].eliminated && candidates[candidate].votes != min_votes)
        {
            return false;
        }
    }
    return true;
}

// here we check candidates with min_votes
// for each candidate from 0 until < candidate_count
// 1. compare votes of current candidate with min_votes
//  1.1 eliminate candidate
// when ends - return

void eliminate(int min_votes)
{
    for (int candidate = 0; candidate < candidate_count; candidate++)
    {
        if (candidates[candidate].votes == min_votes)
        {
            candidates[candidate].eliminated = true;
        }
    }
    return;
}
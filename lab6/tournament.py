# Simulate a sports tournament

import csv
import sys
import random

# this is detailed explanation for beginners in programing like me.)

# N is represents how many World Cup simulations to run
N = 1000


def main():

    # check if the number of command-line arguments is 2
    if len(sys.argv) != 2:
        sys.exit("Usage: python tournament.py FILENAME")

    # we define a list of teams
    teams = []

    # first of all we eead teams into memory from file
    inFile = sys.argv[1]  # `csvInFile` is a variable storing the name of the file from argv[1]

    # then we open file
    with open(inFile) as csvFile:

        # `reader` an object in Python that we can loop over to read the file
        # one row at the time, treating each row as a dictionary
        reader = csv.DictReader(csvFile)

        # iterate each row
        for row in reader:
            teams.append({

                # this is a `string` team name, so just copy that
                'team': row['team'],

                # and here we have to convert `string` rating into `int`
                'rating': int(row['rating'])
            })

    # we define a dictionary which will associate team names with the number of times
    # that team won a simulated tournament (in format: 'winner team', number of wins)
    countWins = {}

    # here we simulate each tournament using `simulate_tournament` function
    # passing all teams to this function from dictionary
    # and determine the winner
    for tournamentN in range(N):

        # calculating the winner of the tournament
        winnerTeam = simulate_tournament(teams)  # return some `winner team`

        # store the value of that winner in `countWins` dictionary ('winner team', number of wins)
        # by looking teams that is already in dictinary
        # and if its there - just add 1 to its wins number, otherwise just initialize to 1 (first time win)
        # using .get function - if winner is exist -> get value of this key and add +1 to it, otherwise - its new winner -> and initialize it with default 0 value + 1
        countWins[winnerTeam] = countWins.get(winnerTeam, 0) + 1

    # we sort the teams in descending order of how many times they won simulations (according to `counts`)
    # and print each team's chances of winning, according to simulation (the estimated probapility that each team wins the World Cup)
    for team in sorted(countWins, key=lambda team: countWins[team], reverse=True):
        print(f"{team}: {countWins[team] * 100 / N:.1f}% chance of winning")


# this function accepts two teams as inputs
# (each team is a dictionary containing the team name and team's rating)
# and simulates a game between them
# If the first team wins - the function returns True
# otherwise - the function returns False
def simulate_game(team1, team2):
    """Simulate a game. Return True if team1 wins, False otherwise."""
    rating1 = team1["rating"]
    rating2 = team2["rating"]
    probability = 1 / (1 + 10 ** ((rating2 - rating1) / 600))
    return random.random() < probability


# this function accepts a list of teams (in a variable called `teams`) as input
# and simulates games between each pair of teams
# the function then returns a list of all of the teams that won the round
def simulate_round(teams):
    """Simulate a round. Return a list of winning teams."""
    winners = []

    # Simulate games for all pairs of teams
    for i in range(0, len(teams), 2):
        if simulate_game(teams[i], teams[i + 1]):
            winners.append(teams[i])
        else:
            winners.append(teams[i + 1])

    return winners


def simulate_tournament(teams):
    """Simulate a tournament. Return name of winning team."""
    # how many rounds we have to simulate here?
    # as many as teams in our dictionary = length of array `teams`
    winners = teams

    # simulate while more than one team left to play
    while len(winners) != 1:
        winners = simulate_round(winners)  # simulating a round
    return winners[0]['team']  # and store name of the team that wins in simulation


if __name__ == "__main__":
    main()

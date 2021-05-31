# user provides how much change is owed
# how to count minimum number of coins with which change can be made?

# this is detailed explanation for beginners in programming like me:)

def main():  # let's open our main function

    # how much change user owed input
    changeOwed = getOwed()

    # minimum coins it be calculator - using as input `how much change is owed`
    coinsMin = calculateCoins(changeOwed)

    # and print out counter of coins
    print(f"{coinsMin}")


def getOwed():  # let's ask user for input (how much change is owed)
    while True:
        question = input("Cash owed: ")
        try:
            changeOwed = float(question)  # we must convert string to float using `float()`
            if changeOwed > 0:  # keep asking until user provides more than 0.0
                break  # valid input is provided -> stop asking
        except ValueError:  # check for exeption - `no value at all`
            None

    return changeOwed  # and return value that we got fron user


def calculateCoins(changeOwed):  # and now let's count minimum amount of coins

    countCoins = 0  # this is our coin counter

    valueCents = round(changeOwed * 100)  # and this is gonna be our cents amount (like in `C` int cents = round(dollars * 100);)

    while valueCents > 0:  # so we have to calculate until all cents will be calculated
        if valueCents >= 25:  # if value of change is greater than 25 cents
            valueCents -= 25  # take one 25 cent coin
        elif valueCents >= 10:  # else if value of change is greater than 10 cents
            valueCents -= 10  # take one 10 cent coin
        elif valueCents >= 5:  # else if value of change is greater than 5 cents
            valueCents -= 5  # take one 5 cent coin
        else:  # else if less than 5 cents left
            valueCents -= 1  # take one 1 cent con
        countCoins += 1  # count each coin taken
    return countCoins  # return our coin counter


main()  # and close our main function
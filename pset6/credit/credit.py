# OK. let's make our credit problem in python
# this is detailed explanation for beginners in programing like me:)

# first of all let's open our main function
def main():
    cardNumber = getCardNumber()  # let's get valid card number from user
    checkSum = calculateCheckSum(cardNumber)  # and calculate cards number check sum
    checkCardType(cardNumber, checkSum)  # check card type and print it


def getCardNumber():  # let's ask user to type in a valid card number
    while True:
        cardNumber = input("Valid card number: ")
        if cardNumber.isnumeric():  # using `.isnumeric()` method to check if all ipnut contains numbers
            break  # if valid -> stop asking
    return cardNumber  # and return its number


def calculateCheckSum(cardNumber):  # let's try another way compare to pset1
    evenNumberSum = 0  # we're gonna count sum of all even numbers
    oddNumberSum = 0  # and sum of all odd numbers
    cardNumber = reversed([int(currentNumber) for currentNumber in cardNumber])  # create `reversed()` copy of card number

    # enumerate() - method adds counter to an iterable and returns it (the enumerate object)
    for i, currentNumber in enumerate(cardNumber):
        # how to check if current number is odd?
        # add to it 1 and then divide by 2 (use modulo %2) and check if remainder is 0 or 1
        if (i + 1) % 2 == 0:
            oddNumber = currentNumber * 2  # Luhn's Algorithm 1. Multiply every other digit by 2
            # if its value greater than 9 (hsa two digits) -> add those digits together
            if oddNumber > 9:
                # for exmple:
                # number 12 contains two digits - 1 and 2
                # how to get 1 from 12?
                # 12 / 10 = 1.2
                # and use method -> int(1.2) = 1 - that give us int from float
                # and how to get 2 from 12?
                # use modulo 12 % 10 that give us remainder 2
                oddNumberSum += int(oddNumber / 10) + oddNumber % 10
            else:  # if our value is lexx than 9 -> just add it to odd numbers sum
                oddNumberSum += oddNumber
        else:  # if currentNumber is even
            evenNumberSum += currentNumber  # just add it to even number sum
    checkSum = evenNumberSum + oddNumberSum  # Luhn's Algorithm 2. Add the sum to the sum of the digits that weren’t multiplied by 2

    # and return card's check sum
    return checkSum


def checkCardType(cardNumber, checkSum):  # now let's make a function that check users card type and validity
    firstDigit = int(cardNumber[0:2])  # we have to check first digits of card number
    cardNumberLength = len(cardNumber)  # and check how many digits in card number
    isLastDigitZero = checkSum % 10  # and check last digit from check sum be `0`

    # Luhn's Algorithm 3. If the total’s last digit is 0 (or, put more formally, if the total modulo 10 is congruent to 0), the number is valid!
    if isLastDigitZero == 0:  # if last digit is zero then card number is valid and can be checked for type
        if firstDigit in [34, 37] and cardNumberLength == 15:  # check for AMEX (first digits 34 or 37 and card length is 15)
            print("AMEX")
        elif (int(cardNumber[0]) == 4) and cardNumberLength in [13, 16]:  # check for VISA (first digit is 4 and card length is 13 or 16)
            print("VISA")
        elif (firstDigit in range(51, 56)) and cardNumberLength == 16:  # check for MASTERCARD (first digits is from 51 to 56 and card length is 16)
            print("MASTERCARD")
    else:  # if not valid card length
        print("INVALID")


main()  # and close our main function
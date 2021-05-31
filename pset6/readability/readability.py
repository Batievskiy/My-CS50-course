# let's make readability on pyton
import re

# this is detailed explanation for beginners in programing like me:)


# let's open ur main function
def main():

    # and ask user for some text
    someText = input("Type some text here: ")

    # let's count all letters in a text using re.findall(pattern, string)
    # - Return all non-overlapping matches of pattern in string, as a list of strings
    # count only letters from a to z and from A to Z
    # then use len() - to count how many letters re.findall() returned
    countLetters = len(re.findall('[a-zA-Z]', someText))

    # count all the words in our text using .split() - Return a list of the words in the string
    # https://www.kite.com/python/answers/how-to-count-the-number-of-words-in-a-string-in-python
    countWords = len(someText.split())

    # and count all sentences in our text using re.findall(pattern, string)
    # all characters that define end of the sentence (. ! ?) patterns to find
    # `+` - means one or more repeats (!!!, ???, ...)
    # `r` - means that the string is to be treated as a raw string
    countSentences = len(re.findall(r'[.!?]+', someText))

    # calculate Coleman Liau's Index
    colemanLiauIndex = calculateColemanLiauIndex(countLetters, countWords, countSentences)

    # and print it out
    printGrade(colemanLiauIndex)


# let's count Coleman-Liau index = 0.0588 * L - 0.296 * S - 15.8
# L = letters / (words / 100); S = sentences / (letters / (words / 100))
def calculateColemanLiauIndex(countLetters, countWords, countSentences):

    wordsPer100 = countWords / 100
    letters = countLetters / wordsPer100
    sentences = countSentences / wordsPer100

    colemanLiauIndex = round(0.0588 * letters - 0.296 * sentences - 15.8)

    return colemanLiauIndex


# and last function for printing Grade + index
# Before Grade 1 - if index < 1; Grade i if between 1 and 16; Grade 16 - if index >=16+
def printGrade(colemanLiauIndex):
    if colemanLiauIndex < 1:
        print("Before Grade 1")
    elif colemanLiauIndex >= 16:
        print("Grade 16+")
    else:
        print(f"Grade {colemanLiauIndex}")


main()  # and close main function

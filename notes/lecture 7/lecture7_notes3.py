# Counting the number of times we've seen each title:

import csv

# let's create a dictioary
titlesDict = {}  # dict() - same

# let's open a file in `read` mode and create a variable called `file`
with open("Favorite TV Shows - Form Responses 1.csv", "r") as file:

    # csv.DictReader - give us best experience
    readerDict = csv.DictReader(file)

    for row in readerDict:
        # .lower() - makes all to lower case
        # .strip() - strips the whitespace from the title
        title = row["title"].strip().lower()
        if title not in titlesDict:
            titlesDict[title] = 1
        titlesDict[title] +=1  # this is our way to count we've seen this title

def frequency(title):
    return titlesDict[title]

# at the bottom of our file
# we need to do a little more work
# iterate over te titlesDict to print out unique titles
# key - is what sort() takes as value to sort by
# reverse - reverses sorting direction
for title in sorted(titlesDict, key=frequency, reverse=True):  # sorted() - sorts the set for us
    print(title, titlesDict[title])  # print out values and its counts

# also we can use this instead defining small function
# key=frequency ->use this instead-> key=lambda title: titles[title],
for title in sorted(titles, key=lambda title: titles[title], reverse=True):
        print(title, titlesDict[title])  # print out values and its counts
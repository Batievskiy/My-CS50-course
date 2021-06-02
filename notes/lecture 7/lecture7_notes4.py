# search for specific show and output the popularity

import csv

title = input("Title: ")

# open a file in `read` mode and name a variable as `file`
with open("Favorite TV Shows - Form Responses 1.csv", "r") as file:
    # create reader for dictionary
    readerDict = csv.DictReader(file)

    # create simple counter of popularity
    counterPopularity = 0
    for row in readerDict:
        # .lower() - makes all to lower case
        # .strip() - strips the whitespace from the title
        if row["title"].strip().lower() == title:
            counterPopularity += 1

print(counterPopularity)
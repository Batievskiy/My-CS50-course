# Cleaning

import csv

# let's open a file in `read` mode and create a variable called `file`
with open("Favorite TV Shows - Form Responses 1.csv", "r") as file:

    # crete a reader
    # and it's gonna be the return value of calling csv.reader on that file
    reader = csv.reader(file)

    # we gonna skip the first row - ecause it's header (timestamp, title, genres)
    next(reader)

    for row in reader:
        # print all elements from row [1] - `titles`
        print(row[1])


    # but csv.reader it not the best approach in python

    # csv.DictReader - give us best experience
    readerDict = csv.DictReader(file)

    for row in readerDict:
        print(row["title"])  # because we can use `names` for rows and columns instead of its indexes


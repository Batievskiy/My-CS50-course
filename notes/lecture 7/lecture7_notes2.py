# Cleaning

# unique titles in our responses:

import csv

# set() is just a collection of values, but eliminates duplicates
titlesSet = set()

# let's open a file in `read` mode and create a variable called `file`
with open("Favorite TV Shows - Form Responses 1.csv", "r") as file:

    # csv.DictReader - give us best experience
    readerDict = csv.DictReader(file)

    for row in readerDict:
        # we add to the `title set` using the add function the current row's title
        # .lower() - makes all to lower case
        # .strip() - strips the whitespace from the title
        titlesSet.add(row["title"].strip().lower())

# at the bottom of our file
# we need to do a little more work
# iterate over te titlesSet to print out unique titles
for title in sorted(titlesSet):  # sorted() - sorts the set for us
    print(title)

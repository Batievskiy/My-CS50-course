# another phonebook
import cs50 import get_string
import csv

file open("phonebook.csv", "a") # open a file in append mode

name = get_string("name: ")
number = get_string("number: ")

writer = csv.writer(file) # csv it expects as input a file that we've already opened

writer.writerow([name, number]) # use a list

file.close() # and close the file

# of another way
with open("phonebook.csv", "a") as file: # open a file in append mode

    name = get_string("name: ")
    number = get_string("number: ")

    writer = csv.writer(file) # csv it expects as input a file that we've already opened

    writer.writerow([name, number]) # use a list

# little bit of Hogwards
import csv

houses = {
    "Gryffindor": 0,
    "Hufflepuff": 0,
    "Ravenclaw": 0,
    "Slytherin": 0
}

with open("Sorting Hat (Responses) - Form Responses 1.csv", "r") as file:
    reader = csv.reader(file) # here we can read a file
    next(reader) # next is skips the row in a file
    for row in reader: # iterate through all rows
        house = row[1] # and copy second column value in a row (name of the house)
        houses[house] += 1 # go to the houses dictionary and go to the house key and increment it by one

for house in houses:
    print(f"{house}: {houses[house]}")
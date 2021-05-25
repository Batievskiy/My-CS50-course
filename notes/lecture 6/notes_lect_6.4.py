import sys
from cs50 import get_string

numbers = [4, 6, 8, 2, 7, 5, 0]

# linear search
if 0 in numbers:
    print("found 0")
    # sys.exit(0)
else:
    print("not found 0")
    # sys.exit(1)

# search names? easy
names = ["Bill", "Charlie", "Fred", "George", "Ginny", "Percy", "Ron"]

# linear search
if "Ron" in names:
    print("found Ron")
    # sys.exit(0)
else:
    print("not found Ron")
    # sys.exit(1)

# phonebook implementation using dictionary data structure
people = {
    "Brian": "+1-617-495-1000",
    "David": "+1-949-468-2750"
}

# search name
name = get_string("name: ")
if name in people:
    number = people[name]
    print("number:", number)

# let's swap some numbers
x = 1
y = 2
print(f"x is {x}, y is {y}")
x, y = y, x # yes, that simple swap
print(f"x is {x}, y is {y}")





from cs50 import get_string

# hello name
answer = get_string("what is your name? ")
print("hello, " + answer)

# or do that
answer = input("what's your name? ")

# f - formatter string
print(f"hello, {answer}") # {} - to plug in an actial value here

# initialize a counter
counter = 0

# change counter by one
counter = counter + 1
counter += 1
# counter++ # does not exist in python


x = 11
y = 10
# if condition
if x < y:
    print("x is less than y") # it necessary to indent your code correctly

# if ... else
if x < y:
    print("x is less than y")
else:
    print("x is not less than y")

# if ... else if ... else
if x < y:
    print("x is less than y")
elif x > y:
    print("x greater than y")
else:
    print("x is equal to y")

# forever loop
while True:
    print("hello, world")
    break # just to stop forever loop

# while i ... until loop
i = 0
while i < 3:
    print("hello, folks")
    i += 1

# for i ... until loop
for i in [0, 1, 2]:     # but this is ugly
    print("not again :|")

# for i ... until loop in a better way
for i in range(3):  # function - range(n):
    print("noooo")

# from 0 to 100+1 step in advance with each second value
for i in range(0, 11, 2):
    print(i)

# bool float int str in python

# range - give back a range of values
# list - is a data type that automaticly resizes
# tuple - something like comma separated values
# dict - dictionaries that allow us to store keys and values
# set - collection of values without duplicates

# get_float / get_int / get_string - from cs50

# import cs50 - whole bunch of functions
# or - from cs50 import get_string



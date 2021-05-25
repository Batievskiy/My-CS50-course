from cs50 import get_int, get_string

# let's print some stupid
for i in range(3):
    print("!")

for i in range(4):
    print("?", end=" ") # `end` is end equals anything we want
print()

print("&" * 4) # lazy way to print something n times

# some bricks
for i in range(3):
    for j in range(3):
        print("#", end=" ")
    print()

# integer overflow not a thing anymore
"""
while True:
    print(i)
    i *= 2
"""

# scores counter
scores = [72, 73, 33] # this is a list that automaticly grow or shrink
# different ways to print out
average = sum(scores) / len(scores)
print(f"Average: {average}")

print(f"Average: {sum(scores) / len(scores)}")

print("Average:", (sum(scores) / len(scores)))

print("Average: " + str(sum(scores) / len(scores)))

# another way of do that
scores = []
for i in range(3):
    scores.append(get_int("Score: ")) # adding an int to a list

average = sum(scores) / len(scores)
print(f"Average: {average}")

# UPPERCASING
s = get_string("Before: ")
print("After:: ", end="")
print(s.upper()) # simple way to uppercase

# pedantical way
for c in s:
    print(c.upper(), end="") # use .upper function here
print()




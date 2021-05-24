# addition with int
from cs50 import get_int, get_string

x = get_int("x: ")
y = get_int("y: ")

print("x - y is ", (x - y))

# and without cs50 library
a = input("a: ") # input in python like get_string in cs50 - takes string (not ints)
b = input("b: ")

print(a + b) # ang it prints out two strings at the line

# just cast fron string to int in python
n = int(input("n: "))
j = int(input("j: "))

print("n * j is ", (n * j))

# but if we divide our numbers?
p = int(input("p: "))
s = int(input("s: "))

print("p / s is ", (p / s))

# we can use prefixes of libraries
x = cs50.get_int("x: ")
y = cs50.get_int("y: ")

# and some conditions
s = get_string("do you agree? : (y / n) ")

if s.lower() in ["y", "yes"]:
    print("agreed")
elif s.lower() in ["n", "no"]:
    print("not agreed")

if x < y:
    print("x < y")
elif x > y:
    print("x > y")
else:
    print("x = y")

# let's meow
def main():
    meow(3)

def meow(n):
    for i in range(n):
        print("meow")

# positive?

from cs50 import get_int

def main():
    i = get_positive_int()
    print(i)

def get_positive_int():
    # in python do ... while loop does not exist
    while True:
        n = get_int("positive int: ")
        if n > 0:
            break
    return n

main()

# at the end we have to write this line of code:
if __name__ == "__main__":
    main()
# of just this: main()






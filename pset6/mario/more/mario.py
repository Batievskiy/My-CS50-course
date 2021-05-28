# this is detailed explanation for beginners in programming like me.)

def main():

    height = getHeight()
    letsDrawPyramid(height)

# check how to play with pyramids in python - https://www.geeksforgeeks.org/programs-printing-pyramid-patterns-python/


def letsDrawPyramid(height):  # let's draw some pyramid using height as input
    
    # number of spaces
    spaces = height - 1

    # number of hashes
    hashes = 1

    # outer look to handle number of rows
    for i in range(0, height):

        # inner loop to handle number of spaces
        for j in range(0, spaces):
            print(end=" ")

        # inner loop to handle number of columns
        for j in range(1, hashes + 1):

            # print hashes
            print("#", end="")

        # printing break
        print("  ", end="")

        # and hashes again.) stupid way, but we can do that.)))
        for j in range(1, hashes + 1):

            # print hashes
            print("#", end="")

        # ending line after each row
        print("")

        # decrement spaces after each loop
        spaces = spaces - 1

        # increment hashes
        hashes = hashes + 1


def getHeight():  # here we create a function that ask user to type some height between 1 and 8
    while True:
        height = input("pyramid's height (1 to 8): ")  #
        try:
            height = int(height)  # convert string to integer
            if (height > 0 and height < 9):  # and check it
                break
        except ValueError:  # if nothing in input
            print("this is NOTHING! Please enter a valid number (1 to 8)")

    return height


main()


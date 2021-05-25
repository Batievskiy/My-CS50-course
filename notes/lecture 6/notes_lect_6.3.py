from sys import argv

# take arguments? sure
if len(argv) == 2:
    print(f"hello, {argv[1]}")
else:
    print("hello, world")

# print argv out
for arg in argv:
    print(arg)

# exit statuses
import sys

if len(sys.argv) != 2:
    print("missing command-line argument")
    sys.exit(1) # like `return 1` in `C`

print(f"helo, {sys.argv[1]}")
sys.exit(0) # like `return 0` in `C`
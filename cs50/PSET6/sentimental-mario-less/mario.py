# import get_int
from cs50 import get_int

# the integer must be between 1 and 8 inclusive
while True:
    n = get_int("Height: ")
    if n > 0 and n < 9:
        break

# print the pyramid
for i in range(n):
    print(" " * (n - (i + 1)) + "#" * (i + 1))

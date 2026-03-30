# import get_float
from cs50 import get_float

# input should be non-negative
while True:
    n = get_float("Change: ")
    if n > 0:
        break

# calculate cents
cents = round(n * 100)
coins = 0

# calculate coins
while cents > 0:
    if cents >= 25:
        cents -= 25
    elif cents >= 10:
        cents -= 10
    elif cents >= 5:
        cents -= 5
    else:
        cents -= 1

    coins += 1

# print coins
print(coins)

# import get_string
from cs50 import get_string

# input should be num
while True:
    cardnum = get_string("Number: ")
    if cardnum.isnumeric():
        break

evens = 0
odds = 0

# reverse card numbers
card = reversed([int(digit) for digit in cardnum])

# Luhn's algorithm
for i, digit in enumerate(card):
    if (i + 1) % 2 == 0:
        digitodd = digit * 2
        if digitodd > 9:
            odds += int(digitodd / 10) + digitodd % 10
        else:
            odds += digitodd
    else:
        evens += digit

sumf = evens + odds
# variables
start = int(cardnum[0:2])
clen = len(cardnum)
sld = sumf % 10

# each card's algorithm
if sld == 0:
    if start in [34, 37] and clen == 15:
        print("AMEX")
    elif start in range(51, 56) and clen == 16:
        print("MASTERCARD")
    elif (int(cardnum[0]) == 4) and clen in [13, 16]:
        print("VISA")
    else:
        print("INVALID")
else:
    print("INVALID")

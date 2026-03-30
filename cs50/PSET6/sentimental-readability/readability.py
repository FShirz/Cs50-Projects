# import libraries
import string
from cs50 import get_string

text = get_string("Text: ")

# count letters
letters = 0

for i in text:
    if (i.isalpha()):
        letters += 1

# count words
words = len(text.split())

# count sentences
sentences = 0

for j in text:
    if (j == '.' or j == '?' or j == '!'):
        sentences += 1

# calculate index
x = words / 100
l = letters / x
s = sentences / x

index = round(0.0588 * l - 0.296 * s - 15.8)

# print grades
if index < 1:
    print("Before Grade 1")
elif index >= 16:
    print("Grade 16+")
else:
    print(f"Grade {index}")

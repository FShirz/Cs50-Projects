
from cs50 import get_int

x = int(input("How many scores you want to submit? "))
scores = []

for i in range(x):
    score = get_int("Score: ")
    scores.append(score)

average = sum(scores) / len(scores)
print(f"Average= {average:.2f}")

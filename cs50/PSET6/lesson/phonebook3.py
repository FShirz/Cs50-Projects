
from cs50 import get_string

people = {
    "Carter": "+16174951000",
    "David": "+16174952000"
}

name = get_string("Name: ").capitalize()

if name in people:
    print(f"Number: {people[name]}")
else:
    print("Not found")

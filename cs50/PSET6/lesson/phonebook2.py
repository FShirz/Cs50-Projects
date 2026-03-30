
from cs50 import get_string

people = [
    {"name": "Carter", "number": "+16174951000"},
    {"name": "David", "number": "+16174952000"}
]

name = get_string("Name: ").capitalize()

for x in people:
    if x["name"] == name:
        number = x["number"]
        print(f"Found {number}")
        break
else:
    print("Not found")

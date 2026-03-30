
names = ["Denise", "Nima", "Melika"]
name = input("Name: ").capitalize()

for n in names:
    if name == n:
        print("Found")
        break
else:
    print("Not found")

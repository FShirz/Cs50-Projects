import csv

with open("phonebook.csv", "a") as file:
    writer = csv.writer(file)
    name = input("name: ")
    number = input("number: ")
    writer.writerow([name, number])

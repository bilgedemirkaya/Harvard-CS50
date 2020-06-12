from cs50 import SQL
from sys import argv
from csv import DictReader 
import csv


db = SQL("sqlite:///students.db")

# check if only one argument passed
if len(argv) != 2:
    exit()

# open the given csv file to read
with open(argv[1]) as csv_file:
    database = csv.DictReader(csv_file)
    
    # split function split the full name into words (split by space)
    for row in database:
        words = row["name"]
        house = row["house"]
        birth = row["birth"]
        names = words.split()
        
        # if person has no middle name then I insert none instead of middle name using temp
        if len(names) == 2:
            names.append(None)
            temp = names[2]
            names[2] = names[1]
            names[1] = temp
            # print(names)
            # insert datas into database called students
            db.execute("INSERT INTO students(first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)",
                       names[0], None, names[2], house, birth)
        else:
            db.execute("INSERT INTO students(first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)",
                       names[0], names[1], names[2], house, birth)

from cs50 import SQL
from sys import argv
from csv import DictReader 
import csv


def main():
    if len(argv) != 2:
        exit()
        
    db = SQL("sqlite:///students.db")
    
    names = db.execute("SELECT first,middle,last,birth FROM students WHERE house = ? ORDER BY last", argv[1])
   
    # print(names)
    # names is a list which every element inside is a dictionary

    for row in names:
        # I take the values from dictionary and put in a list called value
        value = [*row.values()]
        # print(value)
        # if person has no middle name, do not print it
        if value[1] == None:
            print(value[0] + " " + value[2] + " born " + str(value[3]))
            
        else:
            print(value[0] + " " + value[1] + " " + value[2] + " born " + str(value[3]))
 

if __name__ == "__main__":
    main()

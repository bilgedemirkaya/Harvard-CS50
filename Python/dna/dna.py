from csv import reader
from csv import DictReader
import csv
from sys import argv 

# we want to know how many times in maximum particular substring is repeating


def count_substring(s, sub):

    i = 0
    j = len(sub)
    counter = 0

    for a in range(len(s)):
        if s[i:j] == sub:
            temp = 0
            # we find it but it didnt repeat yet so temp is 0
            while s[i:j] == sub:
                temp += 1
                # while there is repeating subs, increment temp and i and j values because we will look further in the string
                i += len(sub)
                j += len(sub)
                # If 'temp' is bigger than the max times it's been repeated, then counter(our answer) will become temp
                if temp > counter:
                    counter = temp
        # If there's no substring in string[i:j] we will increment values to keep seaching.
        else:
            i += 1
            j += 1 

    return counter
    

def main():
    if len(argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        return
    
    # this will open csv file 
    with open(argv[1]) as csv_file:
        database = csv.reader(csv_file)
        # [1:] means delete the index[0] so start from second element
        # next function will give us the first line here, it will stop iteration
        # we got substring list with this line and get rid of others
        first_line = next(database)[1:]
        # print(first_line)
       
        # this will open text file and store it in a string (no need to itare over each line because it is no csv file (only one value inside)
        txt = argv[2]    
        with open(txt) as file:
            str_dna = file.read()
            # now we create an array to store how many repeated sequence for each substring
            personsdna = []
            
            # now we add every result from count function into the array
            # we will send every substring to count function by one by to get the number of repetance
            for sub in first_line:
                # print(sub)
                personsdna.append(count_substring(str_dna, sub))

        # now we will compare every value with others to find the match
        for lines in database:
            person = lines[0]
            # we create another array to store everyone`s -dna repeated- values
            everydna = []
            for val in lines[1:]:  # substract the names 
                everydna.append(int(val)) 
                # we need to make those values integer to compare it
            
            if everydna == personsdna:
                print(person)
                return
        print("No match")
        
        
if __name__ == "__main__":
    main()

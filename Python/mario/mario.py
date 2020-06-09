from cs50 import get_int
# Ask the user Height and make sure it is between 1 to 8 inclusive 


def main():
    h = height()

 # draw coloumns as high as height(n)
    for a in range(1, h + 1, 1): 
        for c in range(0, h - a, 1): 
            print(" ", end="")
            
        for b in range(0, h - (h - a), 1):
            print("#", end="")
            
        # prints the middle spaces
        print("  ", end="")
        
        for b in range(0, h - (h - a), 1):
            print("#", end="")
        print("\n", end="")
        
        
# Function get the input from the user only if it is between 0 to 9


def height():
    while(True):
        h = get_int("Height: ")
        if h > 0 and h < 9:
            break
            
    return h
    
    
main()

from cs50 import get_float


def main():
    qu = 25
    dime = 10
    five = 5
    one = 1
    # to solve this problem: UnboundLocalError: local variable 'Var1' referenced before assignment
    global change
    change = changed()
    count = 0
    
    # convert it to cents and round it to integer
    change = change * 100
    change = round(change)
    # Starting from biggest cent, check if it is bigger than it simultaneously substract the remainder and count the loops so that we know how many coins we collected
    while change >= qu:
        change = change - qu
        count += 1
        
    while change >= dime:
        change = change - dime
        count += 1
        
    while change >= five:
        change = change - five
        count += 1
        
    while change >= one:
        change = change - one
        count += 1
    # print the result
    print("" + str(count))

# get change value from user and ask until it is a positive number


def changed():
    while(True):
        h = get_float("Change owed: ")
        if h > 0:
            break
            
    return h
    
    
main()

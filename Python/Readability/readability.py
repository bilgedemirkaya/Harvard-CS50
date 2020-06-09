from cs50 import get_string


def main():
    
    # get a text from user and grade it
    i = 0
    text = get_string("Text: ")
    n = len(text)
    # find out the letters used in text in total
    for c in range(0, n, 1):
        if text[c] >= 'a' and text[c] <= 'z':
            i += 1
        elif text[c] >= 'A' and text[c] <= 'Z':
            i += 1
    
    # find out the word seperated by ' ' in text in total
    w = 1
    for c in range(2, n, 1):
        if ((text[c] == ' ') and (text[c + 1] >= 'a') and (text[c + 1] <= 'z')) or ((text[c] == ' ') and (text[c + 1] >= 'A')
                                                                                    and (text[c + 1] <= 'Z')):
            w += 1

    # find out the sentences in text in total 
    
    s = 0
    for c in range(0, n, 1):
        if (text[c] == '?') or (text[c] == '!') or (text[c] == '.'):
            s += 1
            
    # convert integer values to float type to get the right result
    
    L = i / w * 100
    
    S = s / w * 100
    
    # used the formula for grading the text
    
    index = (0.0588 * L) - (0.296 * S) - 15.8
    
    index = round(index)
    # print the result
    
    if index < 1:
        print("Before Grade 1")
        
    elif index > 16:
        print("Grade 16+")
        
    else:
        print("Grade " + str(index))
        
        
main()

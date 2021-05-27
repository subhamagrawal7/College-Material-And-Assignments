#Write a program to compute the number of characters, words and lines in string.

def count(name):
    
    numwords = 0
    numchars = 0
    numlines = 0

    split_string = name.split()
    print(split_string)
    numwords = len(split_string)

    for word in split_string:
        numchars += len(word)

    print(name.splitlines())
    numlines = len(name.splitlines())
    
    print ("Words: ", numwords)
    print ("Lines: ", numlines)
    print ("Characters: ", numchars)

str_line = '''hello hi 
how r u doing?
!!!!have a great day!!!!1234'''
print(str_line)
count(str_line)
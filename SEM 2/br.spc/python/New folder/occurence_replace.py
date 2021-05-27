#To get a string from a given string where all occurrences of its first char have been changed to '$', 
# except the first char itself.

def change_char(str1):
    char = str1[0]
    length = len(str1)
    str1 = str1.replace(char, '$')
    str1 = char + str1[1:]
    return str1
print(change_char('restart'))

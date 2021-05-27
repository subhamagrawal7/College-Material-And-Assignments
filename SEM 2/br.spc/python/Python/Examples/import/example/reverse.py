#print string in reverse order.

def reverse_string(string):
    str2=""
    for i in range(len(string)-1,-1,-1):
        str2=str2+string[i]
    print (str2)
a = input("Enter the string to be reversed: ")
reverse_string(a)








'''
a = input("Enter the string to be reversed: ")
print (a[::-1]) 
'''








'''
a = input("Enter the string to be reversed: ")
print ("".join(reversed(a)))
'''
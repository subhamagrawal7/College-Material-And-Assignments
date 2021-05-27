#Write a program that accepts a comma separated sequence of words as input and prints the words in a comma-separated sequence after sorting them alphabetically.


items = input("Input comma separated sequence of words: \n")
list1= items.split(",")
print(list1)

list1.sort()
sorted(list1)                      # will also work
#list1=sorted(list1)               # will also work
#list1=sorted(set(list1))          # will work; but remove duplication due to set()

print(",".join(list1))
#for word in list1:                # alternative of join() method
    #print (word)
    #print (word, end=",")






'''
items = input("Input comma separated sequence of words: \n")
words = [word for word in items.split(",")]
print(words)
print(",".join(sorted(list(set(words)))))         
'''
# above code will also work for, sorted(set(words)) too.
# Program to sort alphabetically the words form a string provided by the user

# change this value for a different result
#my_str = "Hello this Is an Example With cased letters"

# take input from the user
my_str = input("Enter a string: ")

# breakdown the string into a list of words
words = my_str.split()
print(words)

# sort the list
words.sort()
print('sorted list:', words)

# display the sorted words

print("\nThe sorted words are:")
for word in words:
   print(word)




#input: hi hygiene send aws location aasv aa!s 123a
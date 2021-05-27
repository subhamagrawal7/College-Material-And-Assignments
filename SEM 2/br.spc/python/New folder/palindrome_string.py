#Python Program to Check if a string is a Palindrome

string=input(("Enter a string:"))
if(string==string[::-1]):
      print("The string is a palindrome")
else:
      print("Not a palindrome")

print(string[::-1]) #to reverse a string

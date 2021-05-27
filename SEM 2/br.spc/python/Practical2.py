''' Python program to find the
multiplication table (from 1 to 10)'''

#num = 12

# To take input from the user
num = int(input("Display multiplication table of? "))

# use for loop to iterate 10 times
for i in range(1, 11):
   print(num,'x',i,'=',num*i)

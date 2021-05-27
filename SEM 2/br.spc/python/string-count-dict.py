# 1. Write a program to store input string & count of each character of that input string into different dictionary respectively. 
# 2. write a program which takes input from the user for specific number of times and each time, that input and that input's length(or character count) should be stored in dictioanry

'''
str=input("Enter a String: ")
dict = {}

L=len(str)
d={str:L}
print(d)

for i in str:
     dict[i] = str.count(i)
print (dict)

'''



l1=[]
for i in range(1,5):
     a=input("Enter the string ")
     l1.append(a)
print ("List is",l1)
dict1={}
for i in l1:
     dict1[i]=len(i)
print ("Dictionary is",dict1)



#print('------how to take input for dictionary from user-------')
dict={}
for i in range(1,5):
     dict[i]=input()
print ("Dictionary is",dict)






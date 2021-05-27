# Python program to find Area of a circle 

def findArea(r): 
	PI = 3.142
	return PI * (r*r)

r= int(input("Enter the value of radius:"))
# Driver method 
print("Area is %.6f" %findArea(r))



'''

# Python program to find Area of a circle 
import math

def findArea(r):
	return math.pi * (r*r)

r= int(input("Enter the value of radius:"))
# Driver method 
print("Area is %.6f" %findArea(r))

'''
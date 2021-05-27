x = 1
y = 2.8
z = 1j

print(type(x))
print(type(y))
print(type(z))
print("\n---------")

#-----------

x = 1
y = 35656222554887711
z = -3255522

print(type(x))
print(type(y))
print(type(z))
print("\n---------")

#------------

x = 1.10
y = 1.0
z = -35.59

print(type(x))
print(type(y))
print(type(z))
print("\n---------")

#Float can also be scientific numbers with an "e" to indicate the power of 10.
x = 35e3
y = 12E4
z = -87.7e100

print(type(x))
print(type(y))
print(type(z))
print("\n---------")

#Complex numbers are written with a "j" as the imaginary part:
x = 3+5j
y = 5j
z = -5j

print(type(x))
print(type(y))
print(type(z))
print("\n---------")


#Type Conversion
#You can convert from one type to another with the
#int(), float(), and complex() methods:

x = 1 # int
y = 2.8 # float
z = 1j # complex

#convert from int to float:
a = float(x)

#convert from float to int:
b = int(y)

#convert from int to complex:
c = complex(x)

print(a)
print(b)
print(c)

print(type(a))
print(type(b))
print(type(c))

#You cannot convert complex numbers into another number type.
'''d = int(z)
print(d)'''



#-----------
print("\n-----data type is set when you assign a value to a variable------")
x = "Hello World" #str	
x = 20	#int 
x = 20.5        #float	
x = 1j	#complex	
x = ["apple", "banana", "cherry"]	#list	
x = ("apple", "banana", "cherry")	#tuple	
x = {"name" : "John", "age" : 36}	#dict	
x = {"apple", "banana", "cherry"}	#set	
x = True	#bool	


#-----------
print("\n------Setting the Specific Data Type-----")
#If you want to specify the data type

x = str("Hello World")	#str	
x = int(20)	#int	
x = float(20)	#float
print(x)
x = complex(1j)	#complex	
x = list(("apple", "banana", "cherry"))	#list	
x = tuple(("apple", "banana", "cherry"))	#tuple		
x = dict(name="John", age=36)	#dict	
x = set(("apple", "banana", "cherry"))	#set		
x = bool(5)	#bool














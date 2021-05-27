print("-------string Input--------")
username = input("\n Enter username:")
print("\n Username is: " + username)
print(username)
print(type(username))


#----------
print("\n ---------------\n")

print("Enter your name")
x = input()
y = input("age >>>") #age>>> will be printed before input
print("Your name is",x,"and","your age is",y)
print("Your name is " + x +" and"+" your age is "+ y)

print("\n x--->")
print(type(x))
print("\n y--->")
print(type(y))

#----------
print("\n -------int/float Input--------\n")

x = int(input("Enter a number: "))
y = float(input("Enter a number: "))

print(x)
print("%.2f" %y)

print("\n x--->")
print(type(x))
print("\n y--->")
print(type(y))


#----------
print("\n ---------------\n")

x = input("Enter an integer >>>")
y = int(x)
print("You have entered",y)

print("\n x--->")
print(type(x))
print("\n y--->")
print(type(y))


#----------
x = float(input())
print(x)
print(int(7.4)) #This is type conversion



#----------
print("\n-----binary------")
a = 12

# Base 2(binary)
bin_a = bin(a)
print(bin_a)
print(int(bin_a, 2)) #Base 2(binary)



#----------
print("\n-------Conversion to Octal-----")
a = 8

# Base 8(octal)
oct_a = oct(a)
print(oct_a)
print(int(oct_a, 8))



#----------
print("\n------Type conversion to Hexadecimal----")
a = 15

# Base 16(hexadecimal)
hex_a = hex(a)
print(hex_a)
print(int(hex_a, 16))



#----------
print("\n----------sample---------")
octal= oct(int(input(),2))
print(octal)


#-----------
octal = int(input("Enter a octal number: "), 8)
print("\n equivalent decimal no is: " + format(octal))
print(octal)
print(oct(octal))


hexa = int(input("\nEnter a hexadeciaml number: "), 16)
hexstr = "\n equivalent decimal no is: {} "
print(hexstr.format(hexa))

#binaryno = int(input("Enter a number: "), 2)
binstr = "\n  equivalent decimal no is: {binary}"
print(binstr.format(binary= int(input("\nEnter a binary number: "), 2)))













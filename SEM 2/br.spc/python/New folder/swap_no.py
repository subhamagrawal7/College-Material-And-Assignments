#Python Program to Exchange the Values of Two variables Without Using a Temporary Variable

a=int(input("Enter value of first variable (a): "))
b=int(input("Enter value of second variable(b): "))
a=a+b
b=a-b
a=a-b
print("a is:",a," b is:",b)
# sum of first and last digit of a number

n = int(input("Enter a Number : "))
rev = 0
fd = 0
s = 0

ld = n % 10

while n > 0:
    r = n % 10
    rev = rev * 10 + r
    n = n // 10

fd = rev % 10    
s = fd + ld
print("\nSum of first and last digit is :", s)

#just for refernece
print(r, rev, n)

#how to find reverse?

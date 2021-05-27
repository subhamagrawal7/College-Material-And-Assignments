#sum of all digits of a number

n=int(input("Enter a number: "))
total=0
while(n>0):
    dig=n%10
    total=total+dig
    n=n//10
print("The total sum of digits is:",total)

# how to find sum of all digits excluding first and last
# how to find smallest and largest digit of a given number
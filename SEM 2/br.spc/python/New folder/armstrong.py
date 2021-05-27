#Check Armstrong Number 
#A number is called Armstrong number if it is equal to the sum of the cubes of its own digits.
#153 is an Armstrong number since 153 = 1*1*1 + 5*5*5 + 3*3*3.

num = int(input("Enter a number: "))  
sum = 0  
temp = num  
  
while temp > 0:  
   digit = temp % 10  
   sum += digit ** 3  
   temp //= 10  
  
if num == sum:  
   print(num,"is an Armstrong number")  
else:  
   print(num,"is not an Armstrong number")  
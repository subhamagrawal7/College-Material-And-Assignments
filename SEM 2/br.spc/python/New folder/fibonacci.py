#fibonacci series

n=int(input("How many terms you want? "))  
f0=0
f1=1
#count=2

# check if the number of terms is valid  
if n <= 0:  
   print("Plese enter a positive integer")  
elif n == 1: 
    print ("\nThe Fibonacci series is:")   
    print(f0)
else:  
   print ("\nThe Fibonacci series is:")   
   print(f0,"",f1, end='  ') 
   for i in range(2,n):
   #while count < n:
        f2=f0+f1
        print(f2) 
        f0=f1
        f1=f2
        #count += 1

# remove '#' if u want to use while loop for the same
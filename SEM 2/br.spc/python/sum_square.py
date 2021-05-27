#sum and sum of square of first n numbers

def sum(n) :
   sm = 0
   for i in range(1, n+1) :
      sm = sm + i
   return sm

def sqsum(n) :
   sm = 0
   for i in range(1, n+1) :
      sm = sm + pow(i,2)
   return sm

n = int(input("\nEnter upper limit: "))

print("\nnumbers are:")
for i in range(1, n+1) :
      print (i)

print("\nsum upto" , n , ":" , sum(n))
print("\nsum of square upto" , n , ":" , sqsum(n))
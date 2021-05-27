#find the maximum from a list of numbers

l=[]
n=int(input("enter the size of list: "))
for i in range(0,n):
 a=int(input("enter number: "))
 l.append(a)
maxno=l[0]
for i in range(0,len(l)):
 if l[i]>maxno:
     maxno=l[i]
print("The maximum number is: %d"%maxno)


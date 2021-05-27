#Find mean for the given set of numbers in a list.

def mean(a):
    s=sum(a)
    m1=float(s)/len(a)
    print ("Mean is",m1)

list1=[1,2,3,4,5,6,'fgh']
mean(list1)

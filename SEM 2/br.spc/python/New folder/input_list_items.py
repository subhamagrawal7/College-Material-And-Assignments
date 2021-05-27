#write a program which takes list input from the user

# creating an empty list 
lst = [] 
  
# number of elemetns as input 
n = int(input("Enter number of elements : ")) 
  
# iterating till the range 
for i in range(0, n): 
    ele = int(input("input %dth element:" %i))
    lst.append(ele) # adding the element 

#printing list     
print(lst) 

#sort
lst.sort()
print (lst)
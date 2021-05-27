# removing duplicated from list using set() 
'''
#test_list = [1, 5, 3, 6, 3, 5, 6, 1] 
test_list = ['hello', 'hi', 'Hello', 'hello', 'abc'] 
print ("The original list is : " , test_list) 

# using set() to remove duplicated from list 
test_list = list(set(test_list)) 

# printing list after removal
print ("The list after removing duplicates : " + str(test_list)) 
'''




'''
# removing duplicated from list using remove() 

def removeDuplicates(b):
    for item in b:
        if b.count(item) > 1:
            b.remove(item)
    print(b)

a = [1, 1, 2, 3, 3, 'hi', 'hi', 'hello']
removeDuplicates(a)
'''







# Python code to remove duplicate elements without using set() & remove()
def Remove(duplicate): 
	final_list = [] 
	for value in duplicate: 
		if value not in final_list: 
			final_list.append(value) 
	return final_list 
	

duplicate = [2, 4, 10, 20, 5, 2, 20, 4, 'hi','hi'] 
print(Remove(duplicate)) 






#print all the unique elements of a list
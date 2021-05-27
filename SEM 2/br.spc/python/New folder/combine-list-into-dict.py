# combines lists into a dictionary & zip function working

subjects=['ENG','M1','M3','CP','PHY','CHE']
marks=[85,90,91,95,84,87]
z=zip(subjects, marks)
print(z)
d=dict(z)
print (d)


'''
The function takes in iterables as arguments and returns an iterator. 
This iterator generates a series of tuples containing elements from each iterable. 
zip() can accept any type of iterable, such as files, lists, tuples, dictionaries, sets, and so on.
'''
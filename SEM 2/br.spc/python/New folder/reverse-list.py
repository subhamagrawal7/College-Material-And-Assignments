#Write a function reverse to reverse a list. Without using the reverse function.

#Create a slice that starts at the end of the string, 
# and moves backwards.
#In this particular example, the slice statement [::-1] means 
# start at the end of the string and end at position 0,
#move with the step -1, negative one, which means one step backwards.

l = [1,2,3,4,5]
print (l[::-1])

print (l[::-2])

print (l[::-3])

print (l[::-4])

print (l[::-5])

print (l[::-6])

print (l[::1])

print (l[::2])

print (l[::3])

print (l[::4])

print (l[::5])

print (l[::6])
print('----------')
print (l[::0])
#python program to insert a word at given position in string

string = input("enter string: ")
add_string = input("enter string which is to be added: ")
  
print("The original string : " + string) 
print("The added substring : " + add_string) 
  
N = int(input("enter the position where u want to add: "))
  
# using join() + list() + insert() Add substring at specific index  
res = list(string) 
print(res)
res.insert(N, add_string) 
print(res)
res = ''.join(res) 
      
# print result 
print("The string after performing addition : " + res)










'''
line='Name Age Group Class Profession'
arr = line.split()
print(arr)
for i in range(3):
    print(i)
    arr.insert(2, arr[2])
print(arr)
print(' '.join(arr))
'''










'''
# vowel list
vowel = ['a', 'e', 'i', 'u']

# inserting element to list at 4th position
vowel.insert(3, 'o')

print('Updated List: ', vowel)
'''


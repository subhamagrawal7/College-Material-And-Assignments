# perform Linear Search

a = flag=0
items = [5, 7, 10, 12, 15]
print("list of items is", items)
x = int(input("enter item to search:"))
while a < len(items):
 if items[a] == x:
     flag = 1
     break
 a = a + 1
if flag == 1:
 print("item found at position:", a + 1)
else:
 print("item not found")






# print('----how to take a list from user')
# a=[]
# for i in range(5):
#     a.append(input())
# print(a)
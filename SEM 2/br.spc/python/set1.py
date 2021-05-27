#---------
print("\n\n-------Create a Set-------")

thisset = {"apple", "banana", "cherry"}
print(thisset)

#Sets are unordered,
#so you cannot be sure in which order the items will appear.


#----------
print("\n\n-------Access Items-loop-------")

thisset = {"apple", "banana", "cherry"}

for x in thisset:
  print(x)


#---------
print("\n\n-------check-------")

thisset = {"apple", "banana", "cherry"}
print("banana" not in thisset)


#---------
print("\n\n-------Change Items/add new items-------")
#Once a set is created, you cannot change its items, but you can add new items.

print("\n\n-----add one item by add()------")
thisset = {"apple", "banana", "cherry"}
thisset.add("apple")
print(thisset)

print("\n\n-----add more than one item - update()------")
thisset = {"apple", "banana", "cherry"}
thisset.update(["orange", "mango", "grapes"])
print(thisset)


#---------
print("\n\n-------length-------")
thisset = {"apple", "banana", "cherry"}
print(len(thisset))


#--------
print("\n\n----------discard/remove----")
thisset = {"apple", "banana", "cherry"}
thisset.discard("bananaa")
#thisset.remove("bananaa")
print(thisset)


#---------
print("\n\n---------duplicate()----------")
set1 = {"a","b","c"}
set2 = {1,2,3,"c"}
set1.update(set2)
print(set1)















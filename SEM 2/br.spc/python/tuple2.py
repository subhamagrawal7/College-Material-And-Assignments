print("-------Change Tuple Values-------\n")

x = ("apple", "banana", "cherry")
print("----original tuple----")
print(x)
y = list(x)
y[1] = "kiwi"
x = tuple(y)
print("\n----new tuple----")
print(x)


#---------
print("\n\n-------Loop Through a Tuple-------")

thistuple = ("apple", "banana", "cherry")
for x in thistuple:
  print(x)


#---------
print("\n\n-------Check if Item Exists-------")
#use the in keyword

thistuple = ("apple", "banana", "cherry")
if "apple" in thistuple:
  print("Yes, 'apple' is in the fruits tuple")


#--------
print("\n\n-------Tuple Length-------")

thistuple = ("apple", "banana", "cherry")
print(len(thistuple))


#---------
print("\n\n-------Join Two Tuples-------")
#+ operator

tuple1 = ("a", "b" , "c")
tuple2 = (1, 2, 3)

tuple3 = tuple1 + tuple2
print(tuple3)


#---------
print("\n\n-------The tuple() Constructor-------")
#tuple()method

thistuple = tuple(("apple", "banana", "cherry"))
print(thistuple)








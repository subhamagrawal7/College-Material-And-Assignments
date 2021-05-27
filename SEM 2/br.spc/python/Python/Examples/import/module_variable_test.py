import variable

a = variable.person1["age"]
print(a)



import variable as v

a = v.person1["age"]
print(a)



from variable import person1      #suppose module 'variable' has one function 'greeting' and one dictionary 'person1'
print (person1["age"])
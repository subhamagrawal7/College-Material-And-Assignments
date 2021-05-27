#--------Local scope--------

def myfunc():
  x = 300   #local
  print(x)

myfunc()
#print(x)


#---------

print("\n function inside function")

def myfunc():
  x = 300
  def myinnerfunc():
    print(x)
  myinnerfunc()
  
myfunc()



#---------with explanation

print("\n function inside function")
def myfunc():
  print ("inside myfunc")
  x = 300
  def myinnerfunc():
    print ("inside myinnerfunc")
    print(x)
  print ("at the end of myfunc")
  myinnerfunc()
  print ("after executing myinnerfunc")

myfunc()



#--------Global scope--------

'''A variable created outside of a function is
global and can be used by anyone'''

print("\n----global scope----")

x = 300

def myfunc():
  print(x)

myfunc()

print(x)













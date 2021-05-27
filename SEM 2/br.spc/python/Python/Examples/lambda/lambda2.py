# Python code to illustrate cube of a number  
# showing difference between def() and lambda(). 
def cube(y): 
    return y*y*y
  
g = lambda a,b,c: a*b*c 
print(g(7,7,7)) 
  
print(cube(5)) 
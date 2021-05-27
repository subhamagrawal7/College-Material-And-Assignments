Integer = 10
Float = 1.290  
String = "Ayush"  
print("Hi I am Integer ... My value is %d\nHi I am float ... My value is %f\nHi I am string ... My value is %s"%(Integer,Float,String))

print("\nHi I am float ... My value is %0.3f\n" %Float)

print ('\n This is my %s formatted with %d arguments' % ('string', 2))

print('\n %s for %s' % ("tit", "tat"))

print('\n {} and {}'.format("chicken", "waffles"))

print('\n %(last)s, %(first)s %(last)s' % {'first': "James", 'last': "Bond"})

print('\n {last}, {first} {last}'.format(first="James", last="Bond"))

name="jasmina"
print('\n Hello, {}'.format(name))

print(f'\n Hello, {name}!!!!!')

a = 5
b = 10
print(f'\n Five plus ten is {a + b} and not {2 * (a + b)}.')




print("================")

def greet(name, question):
    return f"Hello, {name}! How's it {question}?"

print(greet('Bob', 'going'))


print("================")
def greet(name, question):
    return "Hello, " + name + "! How's it " + question + "?"

print(greet('Class', 'going'))




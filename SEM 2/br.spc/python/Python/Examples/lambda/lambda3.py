'''

def myfunc(n):  	
    return lambda a : a * n

'''


def testfunc(num):
    return lambda x : x * num

result1 = testfunc(10)      

print(result1(9))           #9 is lambda's argument & 10 is testfunc's argument.
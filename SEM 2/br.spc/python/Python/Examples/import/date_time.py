'''
A date in Python is not a data type of its own, 
but we can import a module named datetime to work with dates as date objects.
'''


#Import the datetime module and display the current date

import datetime

x = datetime.datetime.now()     #date contains year, month, day, hour, minute, second, and microsecond
print(x)
print(x.year)                   #year

'''
To create a date, we can use the datetime() class of the datetime module.
The datetime() class requires three parameters to create a date: year, month, day.
'''

y = datetime.datetime(2020, 5, 29)      #timezone - default value 0
print(y)


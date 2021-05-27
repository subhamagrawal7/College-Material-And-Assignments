'''
Python Program to Convert given Kilometer into
Miles
1 km = 0.621371 miles
Meter
1 km = 1000 meter
Centimeter
1 m = 100 centimeter
Feet
1 m = 3.28084 foot
Inch
1 foot = 12 Inch
'''

kilometers = 5.5

# To take kilometers from the user, uncomment the code below
# kilometers = float(input("Enter value in kilometers"))

# calculate 
miles = kilometers * 0.621371
meters = kilometers * 1000
centimeters = meters * 100
foot = meters * 3.28084
inch = foot * 12

print('%0.3f kilometers is equal to %0.3f miles' %(kilometers,miles))
print("%f KM = \n%f miles\n%d meters\n%f centimeters\n%f foot\n%f inch"%(kilometers,miles,meters,centimeters,foot,inch))

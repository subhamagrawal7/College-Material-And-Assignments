#Built-in Modules

import platform

x = platform.system()
print(x)

print("---------")


# use of dir() function
# There is a built-in function to list all the function names (or variable names) in a module. 
# The dir() function can be used on all modules, also the ones you create yourself.

# List all the defined names belonging to the platform module

x = dir(platform)
print(x)



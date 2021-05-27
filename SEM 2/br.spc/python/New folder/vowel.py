#The program takes a string and counts the number of vowels in a string.

'''
def countvowels(string):
    num_vowels=0
    for char in string:
        if char in "aeiouAEIOU":
           num_vowels = num_vowels+1
    return num_vowels


print(countvowels("hello"))
'''




def vowel_count(str): 
	
	count = 0
	vowel = "aeiouAEIOU"
	
	for alphabet in str: 
	    if alphabet in vowel: 
			count = count + 1
	
	print("No. of vowels :", count) 

str = input("Please type a sentence: ")

vowel_count(str)





'''
data = str(input("Please type a sentence: "))
vowels = "aeiou"
for v in vowels:
    print(v, data.lower().count(v))
'''





'''
string = input("Enter a string: ")
vowels=0
for i in string:
      if(i=='a' or i=='e' or i=='i' or i=='o' or i=='u' or i=='A' or i=='E' or i=='I' or i=='O' or i=='U'):
            vowels = vowels+1
print("\n Number of vowels are:", vowels)
'''





'''
print("Enter 'x' for exit.")
ip_str = input("Enter any string to count number of each vowel: ")

if ip_str == 'x':
   exit()

else:

      # string of vowels
      vowels = 'aeiou'

      #ip_str = 'Hello, world!'

      # make it suitable for caseless comparisions
      ip_str = ip_str.casefold()

      # make a dictionary with each vowel a key and value 0
      count = {}.fromkeys(vowels,0)

      print (count)

      # count the vowels
      for char in ip_str:
         if char in count:
             count[char] += 1

      print(count)
'''







#Write a function to find all duplicates in the list.

def FindDuplicates(a):
    for item in a:
        if a.count(item) > 1:
            duplicates.append(item)
    print(duplicates)

a = [1, 1, 2, 3, 3]
duplicates = []
FindDuplicates(a)

print(duplicates)
duplicates_set = set(duplicates)
print(duplicates_set)



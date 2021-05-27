#To compute the frequency of the words of input string and store the count of each word in dictionary

def word_count(str):
    dict_count = dict()
    words = str.split()
    for word in words:
        if word in dict_count:
            dict_count[word] += 1
        else:
            dict_count[word] = 1
    return dict_count
print( word_count('the quick brown fox jumps over the lazy the dog.'))
print("--------------------")
child1={"name":"a","age":12}
child2={"name":"b","age":13}
myfamily={"child1":child1,"child2":child2}
for k,v in myfamily.items():
    if k=="child1":
        print(v)

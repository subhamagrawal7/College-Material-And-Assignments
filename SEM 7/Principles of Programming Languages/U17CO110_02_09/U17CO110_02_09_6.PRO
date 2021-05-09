domains
    integerList = integer*
    charList = char*

predicates
    convert(integerList, charList)

clauses
    convert([],[]).
    convert([H|Tail1],[H|Tail2]):- convert(Tail1,Tail2).
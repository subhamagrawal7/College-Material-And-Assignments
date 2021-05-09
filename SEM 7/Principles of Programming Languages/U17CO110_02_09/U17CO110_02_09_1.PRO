domains
    integerList = integer*

predicates
    append(integerList, integerList, integerList)
    palindrome(integerList, integerList)

clauses

    append([],List,List).
    append([H|List1], List2, [H|List3]):- 
	append(List1, List2, List3).

    palindrome([H],[H]).
    palindrome([H|Tail1], List):- 
	palindrome(Tail1,List2), 
	append([H], List2, Temp), 
	append(Temp, [H], List).
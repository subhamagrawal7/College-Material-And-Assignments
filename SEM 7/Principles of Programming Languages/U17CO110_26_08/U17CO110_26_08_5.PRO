domains
    integerList = integer*
    symbolList = symbol*

predicates
    member(integer,integerList)
    insert(integer,integerList)
    append(integerList,integer,integerList)

clauses 
    insert(X,List):-member(X,List),!,write("Alredy Present"), nl ; append(List,X,Z), write(Z), nl.

    member(X,[X|_]).
    member(X,[_|Tail]):-member(X,Tail).

    append([], Y, [Y]).
    append([H|X], Y, [H|Z]) :- append(X, Y, Z).
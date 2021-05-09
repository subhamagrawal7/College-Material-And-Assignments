domains
integerlist = integer*

predicates
findLength(integerlist,integer)

clauses
findLength([],0).
findLength([_|Tail],N):-
findLength(Tail,N1),
N = 1 + N1.

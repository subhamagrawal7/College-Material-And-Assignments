domains
    x = integer
    l = integer*

predicates
    find(l,x)

clauses

    find([],N) :-
        write("There is no such element in the list"),nl.

    find([Head|Tail],1) :-
        write("The element is ",Head),nl.

    find([Head|Tail],N) :-
        N1 = N-1,
        find(Tail,N1).
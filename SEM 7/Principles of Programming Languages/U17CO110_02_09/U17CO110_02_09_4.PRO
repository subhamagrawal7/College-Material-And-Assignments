domains
    x = integer
    l = integer*

predicates
    mergelist(l,l,l)
clauses
    mergelist([],[],[]).

    mergelist(X,[],X).

    mergelist([],Y,Y).

    mergelist([X|List1],[Y|List2],[X|List]) :-
        X <= Y,!,
       mergelist(List1,[Y|List2],List).

    mergelist([X|List1],[Y|List2],[Y|List]) :-
		X>Y,
        mergelist([X|List1],List2,List).
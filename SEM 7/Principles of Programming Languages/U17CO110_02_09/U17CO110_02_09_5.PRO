domains
list = integer*

predicates 
split(integer,list,list,list)

clauses 

split(_,[],[],[]).

split(X,[H|Tail],[H|LT],GT):-
H<X,
split(X,Tail,LT,GT).

split(X,[H|Tail],LT,[H|GT]):-
H>=X,
split(X,Tail,LT,GT).
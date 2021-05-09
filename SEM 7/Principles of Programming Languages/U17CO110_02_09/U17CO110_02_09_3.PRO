domains
list=symbol*
 
predicates
replace(symbol,symbol,list,list) 

clauses
replace(_,_,[],[]).
replace(X,Y,[X|T],[Y|NT]):-
replace(X,Y,T,NT).
replace(X,Y,[H|T],[H|NT]):-
H<>X,
replace(X,Y,T,NT).
domains
    integerList = integer*

predicates
    
    delete(integer, integerList, integerList)

clauses

    delete(_,[],[]).
	delete(X,[X|T],NT):-
	delete(X,T,NT).
	
	delete(X,[H|T],[H|NT]):-
	H<>X,
	delete(X,T,NT).
predicates
		wordcount(string, integer, integer)
	
	clauses
		wordcount(Str, Count_in, Count_out):-
						fronttoken(Str, Token, Rest),
						Token <> "", !,
						Count1 = Count_in + 1,
						wordcount(Rest, Count1, Count_out).
		wordcount(_, X, X).
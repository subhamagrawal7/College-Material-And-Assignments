domains
		integer_list = integer*
	predicates
		even(integer_list)
	clauses
		even([ ]).
		even([Head | Tail]):-
			Head mod 2 = 0, !,
			write(Head," "),
			even(Tail).
		even([_ | Tail]):-
			even(Tail).

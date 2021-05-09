domains
	list=integer
	lis=list*
predicates
	last(list,lis)
	seclast(list,lis)
clauses
	last(X,[X]).
	last(X,[_|L]):-last(X,L).
	seclast(X,[X|_]).
	seclast(X,[_,Y|Z]) :-seclast(X,[Y|Z]).
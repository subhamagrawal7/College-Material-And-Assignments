domains
	in=integer*
predicates
	sec(in,integer)
clauses
	sec([_|L],N):-N1=N+1,sec(L,N1).
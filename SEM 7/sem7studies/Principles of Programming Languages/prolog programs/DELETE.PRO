domains
	tr=integer*
	t=integer
predicates
	mem(t,tr,tr)
clauses
	mem(X,[X|Y],Y).
	mem(X,[Y|Z],[Y|W]):-mem(X,Z,W).
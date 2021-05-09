domains
	int=integer
	ints=int*
	tree=tree(int,tree,tree);void	
	
predicates
	append(ints,ints,ints)
	pre(tree,ints)
	in(tree,ints)
	post(tree,ints)
clauses
	append([],Y,Y).
	append([X|A],Y,[X,Z]):-append(A,Y,Z).
	pre(void,[]).
	pre(tree(X,L,R),Z):-pre(L,M1),
	pre(R,M2),append([X|M1],M2,Z).

	in(void,[]).
	in(tree(X,L,R),Z):-in(L,M1),
	in(R,M2),append(M1,[X|M2],Z).

	post(void,[]).
	post(tree(X,L,R),Z):-post(L,M1),
	post(R,M2),append(M2,[X],M3),append(M1,M3,Z).
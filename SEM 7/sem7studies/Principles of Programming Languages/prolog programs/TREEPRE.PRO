domains
	int=integer
	ints=int*
	tree=tree(int,tree,tree);void	
	
predicates
	pre(tree,ints)
	preo(tree,ints,ints)
clauses
	pre(T,L):-preo(T,L,[]).
	preo(void,X,X).
	preo(tree(X,L,R),[X|Y],Z):-preo(L,Y,M),
	preo(R,M,Z).
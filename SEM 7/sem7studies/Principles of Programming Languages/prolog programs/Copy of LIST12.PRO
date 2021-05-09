domains
	list=integer
	lis=list*
predicates
	subsum(lis,list,lis)
	
clauses
	subsum([],0,[]).
        subsum([N|L],S,[N|M]):-X=S-N, subsum(L,X,M).
 subsum([N|L],S,M):- subsum(L,S,M).
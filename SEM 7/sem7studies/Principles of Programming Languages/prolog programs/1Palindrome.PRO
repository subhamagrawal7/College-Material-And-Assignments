domains
	int = integer
	intlist = int*
predicates
	reverse(intlist, intlist)
	rev(intlist, intlist,intlist)
	pal(intlist)                
clauses
	pal(L):-reverse(L,L).
	reverse(L1,L2):-rev (L1,L2,[]).
	rev ([],L2,L2):-!.
	rev ([X|Xs],L2,Z):-rev(Xs,L2,[X|Z]).
	 
 	

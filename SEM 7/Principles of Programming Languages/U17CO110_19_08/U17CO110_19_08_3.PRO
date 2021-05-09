domains
list = symbol*

predicates
conc(list,list,list)
findSublist(list,list)

clauses
findSublist(S,L) :- conc(_,L2,L),conc(S,_,L2).

conc([],L,L).
conc([X|L1],L2,[X|L3]) :-conc(L1,L2,L3).


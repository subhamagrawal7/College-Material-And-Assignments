domains
	int=integer
	ints=int*
	t=t(int,t,t);void	
	
predicates
	append(ints,ints,ints)
	pre(t,ints)
	in(t,ints)
	post(t,ints)
	count(t,int)
	height(t,int)
	max(int,int,int)
clauses
	append([],Y,Y).
	append([X|A],Y,[X|Z]):-append(A,Y,Z).
	pre(void,[]).
	pre(t(X,L,R),Z):-pre(L,M1),
	pre(R,M2),append([X|M1],M2,Z).

	in(void,[]).
	in(t(X,L,R),Z):-in(L,M1),
	in(R,M2),append(M1,[X|M2],Z).

	post(void,[]).
	post(t(X,L,R),Z):-post(L,M1),
	post(R,M2),append(M2,[X],M3),append(M1,M3,Z).
	
	count(void,0).
	count(t(X,L,R),Z):-count(L,M1),count(R,M2),
	Z = M1+M2+1.
	
	height(void,0).
	height(t(_,L,R),H):-height(L,M1),height(R,M2),
	max(M1,M2,M3),H=M3+1.
	
	max(A,B,C):-A>B,C=A.
	Max(A,B,C):-B>A,C=B.
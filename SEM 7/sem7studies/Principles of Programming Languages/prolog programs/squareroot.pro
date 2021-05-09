predicates
	solve(real,real,real)
	reply(real,real,real)
	mysqrt(real,real,real)
	equal(real,real)
clauses
	solve(A,B,C):-D= B*B- 4*A*C,reply(A,B,D).
	reply(_,_,D):-D<0,write("No solution"),!.
	reply(A,B,D):-D=0,X=-B/(2*A),write("x=",X),!.
	reply(A,B,D):-mysqrt(D,D,SqrtD),
	X1=(-B+SqrtD)/(2*A),
	X2=(-B-SqrtD)/(2*A),
	write("x1=",X1,"and x2=",X2).
	mysqrt(X,Z,Root):-
	A= Z-(Z*Z-X)/2/Z,
	not(equal(A,Z)),!,
	mysqrt(X,A,Root).
	mysqrt(_,Z,Z).
	equal(X,Y):-X/Y>0.9999,X/Y<1.0000.



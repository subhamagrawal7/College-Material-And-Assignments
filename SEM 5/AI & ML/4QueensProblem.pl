solve(P) :-
	perm([1,2,3,4,5,6,7,8],P), /* P is used to store column no. possible */
	combine([1,2,3,4,5,6,7,8],P,S,D),
	all_different(S),
	all_different(D).
	
combine([X1|X],[Y1|Y],[S1|S],[D1|D]) :-
	S1 is X1 + Y1,    /* Sum of row and column same for anti-diagonal */
	D1 is X1 - Y1,    /* Difference of row and column same for diagonal */
	combine(X,Y,S,D).
combine([],[],[],[]).

all_different([X1|X]) :-
\+member(X1,X),
all_different(X).

all_different([X]).

perm([X|Y],Z) :- 
perm(Y,W),
takeout(X,Z,W).  
perm([],[]).

takeout(X,[F|R],[F|S]) :- /* When X is taken out of the tail of [X|R], [X|S] results, where S is the result of taking X out of R. */
takeout(X,R,S).
takeout(X,[X|R],R). /* When X is taken out of R it results in R */

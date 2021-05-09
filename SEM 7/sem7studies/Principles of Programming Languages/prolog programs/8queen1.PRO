solve(P) :-
     perm([1,2,3,4,5,6,7,8],P), 
     combine([1,2,3,4,5,6,7,8],P,S,D),
     all_diff(S),
     all_diff(D).

combine([X1|X],[Y1|Y],[S1|S],[D1|D]) :-
     S1 is X1 +Y1,
     D1 is X1 - Y1,
     combine(X,Y,S,D).
combine([],[],[],[]).

all_diff([X|Y]) :-  \+member(X,Y), all_diff(Y).
all_diff([X]).
 Y1 - Y =\= X - X1,
 noattack(X/Y,Others).
 
member(Item,[Item|Rest]).
 
member(Item,[First|Rest]) :-
 member(Item,Rest).
 
template([1/Y1,2/Y2,3/Y3,4/Y4,5/Y5,6/Y6,7/Y7,8/Y8]).
	 
 	

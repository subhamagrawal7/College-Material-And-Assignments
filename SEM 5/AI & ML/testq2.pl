solve([H|T],P):-
perm([1,2,3,4],P),
combine([1,2,3,4],P,S,D),
all_different(S),
all_different(D),
write(P),
nl.

all_different([H]).
all_different([H|T]):-
\+member(H,T),
all_different(T).

combine([],[],[],[]).	
combine([X1|X],[Y1|Y],[S1|S],[D1|D]):-
S1 is X1+Y1,
D1 is X1-Y1,
combine(X,Y,S,D).

takeout(X,[X|R],R).
takeout(X,[F|R],[F|S]):-
takeout(X,R,S).

insert(X,List,BiggerList):-
takeout(X,BiggerList,List).

perm([],[]).
perm([H|T],P):-
perm(T,P1),
insert(H,P1,P).
findLength([],0).
findLength([H|T],L):-
findLength(T,L1),
L is L1+1.

evenLength([H|T]):- 
findLength([H|T],X), 
0 is mod(X,2).

displayList([H|T]):-
write(H),
write(' '),
displayList(T).

sumOfList([],0).
sumOfList([H],H).
sumOfList([H|T],X):-
sumOfList(T,X1),
X is X1+H,!.

check([H|T]):-
(evenLength([H|T]) -> sumOfList([H|T],X),write(X);displayList([H|T])).
member1(X,[X|L]).
member1(X,[Head|Tail]):-
member1(X,Tail).

conc([],L,L).
conc([X|L1],L2,[X|L3]):-
conc(L1,L2,L3).

del(_,[],[]).
del(X,[X],[]).
del(X,[X|Tail],Tail):-!.
del(X,[Y|Tail1],[Y|Tail2]):-
del(X,Tail1,Tail2),!.

listAppend(A,L1,L2):-
member(A,L1),!.
listAppend(A,L1,[A|L1]).

insert(X,List,BiggerList):-
del(X,BiggerList,List).

add(X,L,[X|L]).

sublist(S,L):-
conc(L1,L2,L),
conc(S,L3,L2).

perm([],[]).
perm([X|L],P):-
perm(L,L1),
insert(X,L1,P).

search(H,[H|_]).
search(X,[H|Tail]):-
search(X,Tail).

findLen([],0).
findLen([H|Tail],L):-
findLen(Tail,L1),
L is L1+1.

findNth([H|Tail],1,H).
findNth([H|Tail],N,X):-
N>1,
N1 is N-1,
findNth(Tail,N1,X),!.

inceach([],[]).
inceach([H|Tail],[Y|Tail1]):-
Y is H+1,
inceach(Tail,Tail1),!.

reverseList(InputList,OutputList):-
reversefin(InputList,[],OutputList).
reversefin([],OutputList,OutputList).
reversefin([H|Tail],L1,L2):-
reversefin(Tail,[H|L1],L2).

firstLast([H],H,H).
firstLast([H|Tail],H,L):-
firstLast(Tail,F,L),!.

vowelYes(X):-
member(X,[a,e,i,o,u]).
nrvowel([],0).
nrvowel([H|Tail],L):-
nrvowel(Tail,L1),
(vowelYes(H) -> L is L1+1;L is L1).

noDub([],[]).
noDub([X],[X]).
noDub([X1,X2|Tail],Z):-
	del(X1,[X2|Tail],Y2),
	noDub(Y2,Z1),
	listAppend(X1,Z1,Z).

intersect([H],[H],[H]).
intersect([],[],[]).
intersect([H|Tail1],[Y|Tail2],L1):-
intersectfin([H|Tail1],[Y|Tail2],[],L),
noDub(L,L1).

/*(member(H,[Y|Tail2]) -> add(H,L,L); member(Y,[H|Tail1]) -> add(Y,L,L)),
intersect(Tail1,Tail2,L).*/

intersectfin([],L2,OutputList,OutputList).
intersectfin([H|Tail1],[Y|Tail2],L1,L2):-
(member(H,[Y|Tail2]) -> intersectfin(Tail1,[Y|Tail2],[H|L1],L2);
intersectfin(Tail1,[Y|Tail2],L1,L2)).
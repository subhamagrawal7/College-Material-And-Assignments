fact(0,X) :-
	X is 1.

fact(N,X) :-
	N>0,
	Y is N-1,
	fact(Y,X1),
	X is X1*N.
	
fib(1,X) :-
	X is 1.

fib(2,X) :-
	X is 1.
	
fib(N,X) :-
	N>2,
	Y is N-1,
	Z is N-2,
	fib(Y,X1),
	fib(Z,X2),
	X is X1+X2.

gcd(A,0,X) :-
	X is A.
	
gcd(A,B,X) :-
	B>0,
	Y is mod(A,B),
	gcd(B,Y,X).

lcm(A,B,X) :-
	gcd(A,B,X1),
	Z is A*B,
	X is Z / X1.
	
% searching element in list
find(H,[H|TAIL]).
find(X,[H|TAIL]) :- find(X,TAIL).

% length of list
findlength([],0).
findlength([H|T], N) :- findlength(T,X), N is X+1.

% find first and last element
firstlast([],[],[]).
firstlast([H],H,H).
firstlast([H|T],H,L) :- firstlast(T,F,L).

% nth element
findnth([H|T],H,1).
findnth([H|T],X,N) :- N1 is N-1,N1 > 0,findnth(T,X,N1).

% increment each element
incrementeach([],[]) .
incrementeach([X|Xs],[Y|Ys]) :-(number(X) -> Y is X+1 ; Y = X ),incrementeach(Xs,Ys). % X is input Y is output

% reverse the list
reverse_list(Inputlist,Outputlist) :- reverse(Inputlist,[],Outputlist).    
reverse([],Outputlist,Outputlist).    
reverse([Head|Tail],List1,List2) :- reverse(Tail,[Head|List1],List2).

% list has even number of elements
evenlength([H|T]) :- findlength([H|T],X), 0 is mod(X,2).

% find number of vowels
vowel(X):- find(X,[a,e,i,o,u]).
nr_vowel([],0).
nr_vowel([X|T],N):- vowel(X),nr_vowel(T,N1), N is N1+1,!. % ! for no backtracking and no checking next conditions
nr_vowel([X|T],N):- nr_vowel(T,N).

% remove duplicates
noDub([],[]).
noDub([X],[X]).
noDub([X1,X2|Tail],Z):-
	listDelete(X1,[X2|Tail],Y2),
	noDub(Y2,Z1),
	listAppend(X1,Z1,Z).
	
% list append
listAppend(A,List1,List1):- member(A,List1),!.
listAppend(A,Tail,[A|Tail]).

% list Delete(element to be deleted,list,output list)
listDelete(_,[],[]).
listDelete(X,[X],[]).
listDelete(X,[X|Tail],Tail):-!.
listDelete(X,[Y|Tail],[Y|Tail1]):-
	listDelete(X,Tail,Tail1),!.
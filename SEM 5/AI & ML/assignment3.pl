%factorial of number
fact(1,0).
fact(X,N) :- N>0,Y is N-1,fact(X1,Y),X is X1*N.

%fibonacci of two numbers
fib(1,1).
fib(2,1).
fib(N,X) :- N>2,Y is N-1,Z is N-2, fib(Y,X1),fib(Z,X2), X is X1+X2.

%gcd and lcm of two numbers
gcd(0,B,B).
gcd(A,B,X) :- A>0,Y is mod(B,A), gcd(Y,A,X1), X is X1.
lcm(A,B,X) :- Y is A*B,gcd(A,B,Z),X is Y/Z.

%searching element in list
find(X,[X|TAIL]).
find(X,[Y|TAIL]) :- find(X,TAIL).

%length of list
findlength([],0).
findlength([H|T], N) :- findlength(T,X), N is X+1.

%find first and last element
firstlast([],F,L).
firstlast([H],F,H).
firstlast([H|T],H,L) :- firstlast(T,F,L).

%nth element
findnth([H|T],H,1).
findnth([H|T],X,N) :- N1 is N-1,N1 > 0,findnth(T,X,N1).

%increment each element
incrementeach([],[]) .
incrementeach([X|Xs],[Y|Ys]) :-(number(X) -> Y is X+1 ; Y = X ),incrementeach(Xs,Ys).

%reverse the list
reverse_list(Inputlist,Outputlist) :- reverse(Inputlist,[],Outputlist).    
    
reverse([],Outputlist,Outputlist).    
reverse([Head|Tail],List1,List2) :- reverse(Tail,[Head|List1],List2).

%list has even number of elements
evenlength([H|T]) :- findlength([H|T],X), 0 is mod(X,2).

%find number of vowels
vowel(X):- find(X,[a,e,i,o,u]).
nr_vowel([],0).
nr_vowel([X|T],N):- vowel(X),nr_vowel(T,N1), N is N1+1,!.
nr_vowel([X|T],N):- nr_vowel(T,N).
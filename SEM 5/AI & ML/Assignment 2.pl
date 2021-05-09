% parent(Parent, Child)

%

parent(f,i).

parent(w,s1).

parent(w,d).

parent(d,s2).

parent(f,s2).

parent(d,i).

parent(i,s1).

parent(i,d).


% female(Person)

%

female(w).

female(d).

% male(Person)

%

male(f).

male(s1).

male(s2).

male(i).

% spouse(Person,Person)

%

spouse(f,d).

spouse(i,w).

spouse(w,i).

spouse(d,f).

mother(X,Y) :-
	parent(X,Y),
	female(X).
	
father(X,Y) :-
	parent(X,Y),
	male(X).

sibling(X,Y) :-
	parent(Z,X),
	parent(Z,Y),
	X\==Y.
	
parentlaw(X,Y) :-
	parent(X,Z),
	spouse(Z,Y).

fatherInLaw(X,Y) :-
	male(X),
	parentlaw(X,Y).
	
motherInLaw(X,Y) :-
	female(X),
	parentlaw(X,Y).

siblingInLaw(X,Y) :-
	sibling(X,Z),
	spouse(Z,Y).

brotherInLaw(X,Y) :-
	male(X),
	siblingInLaw(X,Y).
	
sisterInLaw(X,Y) :-
	female(X),
	siblingInLaw(X,Y).
	
uncle(X,Y) :-
	male(X),
	sibling(X,Z),
	parent(Z,Y).
	
uncle(X,Y) :-
	male(X),
	siblingInLaw(X,Z),
	parent(Z,Y).

grandfather(X,Z) :-
	parent(X,Y),
	parent(Y,Z),
	male(X).
	
grandfather(X,Z) :-
	parentlaw(X,Y),
	parent(Y,Z),
	male(X).

sonInLaw(X,Y) :-
	male(X),
	spouse(X,Z),
	parent(Y,Z).
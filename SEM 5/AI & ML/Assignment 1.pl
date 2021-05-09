% Program:  family.pl

% Source:   Prolog

%

% Purpose:  This is the sample program for the Prolog Lab in AIML

%           It is a simple Prolog program to demonstrate how prolog works.

%

% History:  Original code by Barry Drake

% parent(Parent, Child)

%

parent(albert, jim).

parent(albert, peter).

parent(jim, brian).

parent(john, darren).

parent(peter, lee).

parent(peter, sandra).

parent(peter, james).

parent(peter, kate).

parent(peter, kyle).

parent(brian, jenny).

parent(irene, jim).

parent(irene, peter).

parent(pat, brian).

parent(pat, darren).

parent(amanda, jenny).

grandparent(X,Y):-parent(X,T),parent(T,Y).

older(Person1, Person2) :-

        yearOfBirth(Person1, Year1),

        yearOfBirth(Person2, Year2),

        Year2 > Year1.
		
sibling(X,Y) :-
		parent(Z,X),
		parent(Z,Y),
		X\=Y.
predecessor(X,Z) :-
		parent(X,Z).
predecessor(X,Z) :-
		parent(X,Y),
		predecessor(Y,Z).
sister(X,Y) :-
		sibling(X,Y),
		female(X).
noOfMales(X,Z) :-
		aggregate_all(count,male(X),Z).
noOfFemales(X,Z) :-
		aggregate_all(count,female(X),Z).
 

% female(Person)

%

female(irene).

female(pat).

female(lee).

female(sandra).

female(jenny).

female(amanda).

female(kate).

 

% male(Person)

%

male(albert).

male(jim).

male(peter).

male(brian).

male(john).

male(darren).

male(james).

male(kyle).

 

 

% yearOfBirth(Person, Year).

%

yearOfBirth(irene, 1923).

yearOfBirth(pat, 1954).

yearOfBirth(lee, 1970).

yearOfBirth(sandra, 1973).

yearOfBirth(jenny, 2004).

yearOfBirth(amanda, 1979).

yearOfBirth(albert, 1926).

yearOfBirth(jim, 1949).

yearOfBirth(peter, 1945).

yearOfBirth(brian, 1974).

yearOfBirth(john, 1955).

yearOfBirth(darren, 1976).

yearOfBirth(james, 1969).

yearOfBirth(kate, 1975).

yearOfBirth(kyle, 1976).
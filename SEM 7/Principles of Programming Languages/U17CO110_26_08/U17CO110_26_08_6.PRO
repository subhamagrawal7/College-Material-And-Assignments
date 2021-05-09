domains
    x = integer
    l = integer*

predicates
    countEven(l,x)
	countOdd(l,x)
	count(l)
	
clauses
    countEven([],0).
	
	countEven([H|T],R):-
		H mod 2 = 0,
		countEven(T,R1),
		R = R1+1.
	countEven([H|T],R):-
		H mod 2 = 1,
		countEven(T,R).
		
	countOdd([],0).
	countOdd([H|T],R):-
		H mod 2 = 1,
		countOdd(T,R1),
		R = R1+1.
	countOdd([H|T],R):-
		H mod 2 = 0,
		countOdd(T,R).
		
	count(List):-
		countEven(List,X),
		write("The no. of even numbers is = ",X),nl,
		countOdd(List,Y),
		write("The no. of odd numbers is = ",Y),nl.
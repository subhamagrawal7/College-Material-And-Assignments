predicates
    between(integer,integer,integer)
	go(integer, integer,integer)

clauses   
    between(X,Y,Z):- go(X,X,Z).
    go(X,Y,Z):- Y>Z,!.
	go(X,Y,Z):- Y<=Z,
		    write(Y," "),
		    Y1= Y+1,
		    go(X,Y1,Z).
					
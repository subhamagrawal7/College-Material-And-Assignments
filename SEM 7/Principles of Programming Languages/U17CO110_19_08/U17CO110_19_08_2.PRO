predicates
    between(integer,integer)

goal
    write("Enter the first number: "),
    readint(X),
    write("Enter the second number: "),
    readint(Y),
    write("The numbers between the two numbers are: "),
    between(X,Y).

clauses   
    between(Y,Y).
    between(X,Y):- X1 = X+1,
    		       X1 < Y,
    		       write(X1," "),
                   between(X1,Y).
                   
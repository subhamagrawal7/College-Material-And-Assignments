predicates
    fibonacci(integer, integer, integer)

goal
    write("Enter a number: "),
    readint(N),nl,
    write("The first ", N, " fibonacci numbers are :"),nl,
    fibonacci(0,1,N).

clauses
    fibonacci(X,Y,N):- X <= N, write(X, " "), Z = X + Y, fibonacci(Y,Z,N1), !.
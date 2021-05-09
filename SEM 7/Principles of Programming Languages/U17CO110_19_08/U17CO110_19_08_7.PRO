predicates
    start
    factorial(integer,integer)

clauses
    start:-
        write("Enter non negative number = "),
        readint(N),
        Result = 1,
        factorial(N,Result).

    factorial(N,Result):-
        N <> 0,
        NewResult = N * Result,
        NewNum = N - 1,
        factorial(NewNum,NewResult).

    factorial(_,Result):-
        write("Factorial = ",Result),nl.
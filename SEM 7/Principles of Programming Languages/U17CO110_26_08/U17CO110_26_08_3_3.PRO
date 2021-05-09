predicates
    raised_to(real,integer,real)

clauses
    raised_to(X,1,X).
    raised_to(X,I,Result):- I > 1, P = I-1, raised_to(X,P,Partial), Result = X * Partial. 
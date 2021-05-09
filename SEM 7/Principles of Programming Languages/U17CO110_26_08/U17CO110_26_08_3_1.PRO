predicates
    findgcd(integer, integer, integer)

clauses
    findgcd(X,0,X):- !.
    findgcd(0,X,X):- !.
    findgcd(X,Y,D):- X > Y, ! , Rem = X mod Y, findgcd(Y, Rem, D).
    findgcd(X,Y,D):- Rem = Y mod X, findgcd(X, Rem, D).
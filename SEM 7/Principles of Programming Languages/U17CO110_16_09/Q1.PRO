domains
list = integer*

database
mult(integer,integer,integer)

predicates
run
member(integer,list)

clauses

run:-
retractall(mult(_,_,_)),
L = [1,2,3,4,5,6,7,8,9,10],
member(X,L),
member(Y,L),
Product = X * Y,
assertz(mult(X,Y,Product)),
fail.

run:-

write("I am ready with the tables "),nl,
write("You may now type goals like mult(X1,X2,Product) " ),nl,
exit.

member(X,[X|_]).
member(X,[_|T]) :- member(X,T).
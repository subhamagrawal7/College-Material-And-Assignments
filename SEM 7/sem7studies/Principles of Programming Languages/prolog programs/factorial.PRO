 /* Recursive program to compute factorials. */

predicates
   factorial(integer, real)
clauses
      factorial(1, 1) :- !.
   factorial(X, FactX) 
			 :-  Y = X-1,                                         			factorial(Y, FactY),
                  FactX = X*FactY.
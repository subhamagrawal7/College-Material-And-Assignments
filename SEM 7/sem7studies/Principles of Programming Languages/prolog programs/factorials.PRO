/* Recursive program to compute factorials. */

predicates
   factorial(integer, integer)
clauses
      factorial(1, 1) :- !.
   factorial(FactX, X ) 
			 :-  Y = X-1,                                         			factorial( FactY, Y),
                  FactX = X*FactY.

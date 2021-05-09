predicates
read_grade(integer)
evaluate_grade(integer,symbol)
start
clauses

start:-
  read_grade(X) ,
  evaluate_grade(X,R),
  write("Your Grade is ") ,
  write(R) ,
  nl.

read_grade(X) :-
  write("please enter your marks: ") ,
  readint(X).
  
evaluate_grade( X ,aa) :- X >= 90,!.
evaluate_grade( X ,ab) :- X >= 80 , X < 90,! .
evaluate_grade( X ,bb) :- X >= 70 , X < 80,! .
evaluate_grade( X ,bc) :- X >= 60 , X < 70,! .
evaluate_grade( X ,cc) :- X >= 50 , X < 60,! .
evaluate_grade( X ,cd) :- X >= 40 , X < 50,! .
evaluate_grade( X ,dd) :- X >= 30 , X < 40,! .
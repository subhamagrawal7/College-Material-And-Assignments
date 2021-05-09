domains
  int  = integer
  ints = int*
predicates
  insertion_sort(ints,ints)
  insert(int,ints,ints)
clauses                                                       
  insertion_sort([],[]).
  insertion_sort([X|T],Y):-insertion_sort(T,Z),
  insert(X,Z,Y).
  insert(X,[Y|T],[Y|T1]):-X>Y,!,insert(X,T,T1).
  insert(X,Y,[X|Y]).
domains
  int  = integer
  ints = int*
predicates
  insertion_sort(ints,ints)
  insertion_sort_1(ints,ints,ints)
  insert(ints,int,ints)
clauses

                                                         
insertion_sort(Xs, Ys):-insertion_sort_1(Xs, [], Ys).

insertion_sort_1([], Ys, Ys).
insertion_sort_1([X|Xs], Ys0, Ys):-
  insert(Ys0, X, Ys1),
  insertion_sort_1(Xs, Ys1, Ys).

insert([Y|Ys], X, [Y|Zs]):-Y < X, !, insert(Ys, X, Zs).
insert(Ys, X, [X|Ys]).

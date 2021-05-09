domains
  int  = integer
  ints = int*
predicates
  bubble_sort(ints,ints)
  append(ints,ints,ints)
clauses

/* bubble_sort(Xs, Ys) is true if Ys is a sorted permutation of the        */
/*   list Xs.                                                              */
bubble_sort(Xs, Ys):-
  append(Ws, [A,B|Zs], Xs),
  B < A,
  append(Ws, [B,A|Zs], Vs),
  bubble_sort(Vs, Ys), !.
bubble_sort(Xs, Xs).

/* append(Xs, Ys, Zs) is true if Zs is the result of appending the list Xs */
/*   to the list Ys.                                                       */
append([], Ys, Ys).
append([X|Xs], Ys, [X|Zs]):-append(Xs, Ys, Zs).

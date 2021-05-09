domains
  int  = integer
  ints = int*
predicates
  merge_sort(ints,ints)
  merge_sort_1(int,ints,ints,ints)
  ordered_merge(ints,ints,ints)
  length(ints,int)
  length_1(ints,int,int)
clauses
merge_sort(List, SortedList):-
  length(List, Length),
  merge_sort_1(Length, List, SortedList, []).
 
merge_sort_1(0, Rest, [], Rest):-!.
merge_sort_1(1, [A|Rest], [A], Rest):-!.
merge_sort_1(2, [A,B|Rest], C, Rest):-A <= B, !, C = [A,B].
merge_sort_1(2, [A,B|Rest], C, Rest):-/* A > B, */ !, C = [B,A].
merge_sort_1(N, List, Sorted, Rest):-
  N1 = N div 2, N2 = N - N1,
  merge_sort_1(N1, List, SortedLeft, TempList),
  merge_sort_1(N2, TempList, SortedRight, Rest),
  ordered_merge(SortedLeft, SortedRight, Sorted).
 
ordered_merge([X|Xs], [Y|Ys], [Y|Zs]):-
  Y <= X, !,
  ordered_merge([X|Xs], Ys, Zs).
ordered_merge([X|Xs], Ys, [X|Zs]):-
  ordered_merge(Xs, Ys, Zs).
ordered_merge([], Ys, Ys).

length(Xs, L):-length_1(Xs, 0, L).

length_1([], L, L).
length_1([_|Xs], L0, L):-L1 = L0 + 1, length_1(Xs, L1, L).

check_determ
domains
  int  = integer
  ints = int*
  tree = tree(int,tree,tree) ; void
predicates
  insert_leaf(int,tree,tree)
  delete_node(int,tree,tree)
  left_rest(tree,int,tree)
  pre_order(tree,ints)
  pre_order_dl(tree,ints,ints)
  in_order(tree,ints)
  in_order_dl(tree,ints,ints)
  post_order(tree,ints)
  post_order_dl(tree,ints,ints)
clauses

/* insert_leaf(X, Tree, Tree1) is true if Tree1 is the result of inserting */
/*   the element X as a leaf in the ordered binary tree Tree.  If the      */
/*   element X is already in the tree, the tree is unchanged.              */
insert_leaf(X, void, tree(X,void,void)).
insert_leaf(X, tree(X,L,R), Tree):-!, Tree = tree(X,L,R).
insert_leaf(X, tree(Y,L,R), tree(Y, L1, R)):-
  X < Y,
  !,
  insert_leaf(X, L, L1).
insert_leaf(X, tree(Y,L,R), tree(Y,L,R1)):-
  X > Y,
  insert_leaf(X, R, R1).
 
/* delete_node(X, Tree, Tree1) is true if Tree1 is the result of deleting  */
/*   the element X from the ordered binary tree Tree.                      */
delete_node(X, tree(X,L,void), L):-!.
delete_node(X, tree(X,L,R), tree(Y, L, R1)):-
  !,
  left_rest(R, Y, R1).
delete_node(X, tree(Y,L,R), tree(Y, L1, R)):-
  X < Y,
  !,
  delete_node(X, L, L1).
delete_node(X, tree(Y,L,R), tree(Y,L,R1)):-
  X > Y,
  delete_node(X, R, R1).
 
/* left_rest(Tree, Left, Rest) is true if Left is the leftmost element in  */
/*   the binary tree Tree, and Rest is the rest of the tree.               */
left_rest(tree(X,void,R), X, R):-!.
left_rest(tree(X,L,R), Y, tree(X,L1,R)):-left_rest(L, Y, L1).
 
/* pre_order(Tree, L) is true if L is a pre-order traversal of the binary  */
/*   tree Tree.                                                            */
pre_order(T, L):-pre_order_dl(T, L, []).

pre_order_dl(tree(X,L,R), [X|Xs], Zs):-
  pre_order_dl(R, Ys, Zs),
  pre_order_dl(L, Xs, Ys).
pre_order_dl(void, Xs, Xs).
 
/* in_order(Tree, L) is true if L is an in-order traversal of the binary   */
/*   tree Tree.                                                            */
in_order(T, L):-in_order_dl(T, L, []).

in_order_dl(tree(X,L,R), Xs, Zs):-
  in_order_dl(R, Ys, Zs),
  in_order_dl(L, Xs, [X|Ys]).
in_order_dl(void, Xs, Xs).
 
/* post_order(Tree, L) is true if L is a post-order traversal of the       */
/*   binary tree Tree.                                                     */
post_order(T, L):-post_order_dl(T, L, []).

post_order_dl(tree(X,L,R), Xs, Zs):-
  post_order_dl(R, Ys, [X|Zs]),
  post_order_dl(L, Xs, Ys).
post_order_dl(void, Xs, Xs).


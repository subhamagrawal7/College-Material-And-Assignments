INT is integer
PL=INT* % plain 3x3 position position in a form of list
LPL=PL* % total list of list of positions

puzzle(PL,LPL,INT,INT,INT) % main search.

% PL-current position, LPL-current total list of positions, INT-

% steps counter , INT-total steps limitation , INT-local/brunch steps limitation

BFS(PL,PL,LPL,LPL,INT,INT,INT) % BFS STRATEGY. PL-input, PL,-output

% LPL-input, LPL-output, INT-steps counter-initial step =0, INT-total limit, INT-% brunch limit

move(PL,PL) % general move. PL-input position, PL-output position

% this group of predicates describes puzzle 3x3 moves in a form of list

move_left(PL,PL)

move_right(PL,PL)

move_up(PL,PL)

move_down(PL,PL)

member(PL,LPL) % membership PL of LPL

writel(PL) % writes current position PL list in plain 3x3 form

out(LPL) % main output writing

invord(LPL,LPL,LPL) % inversion of order of elements of the list

% LPL -input , LPL-initial list=[], LPL-output

writepuz(LPL,INT) % writes LPL search list, INT- steps counter


% Main search

% End of search

puzzle(L1,L2,I,N,_):-I<N % total limit

L1=[0,1,2,3,4,5,6,7,8], % standard output. You input any here.

out(L2),!.

% body of search

puzzle(L1,L2,I,N,M) :-
I<N,K=I+1,BFS(L1,L3,L2,L4,K,J,M),puzzle(L3,L4,J,N,M),!.

% this is the main search

% BFS strategy

BFS(L1,L2,L3,L4,I,J,M):-move(L1,L2), % general move

not(member(L2,L3)), % cuts repeating positions. No loops.

L4=[L2|L3],

S=M×trunc(I/M),not(S=I), % this is main action , forming the current brunch

% limit, connected with backtracking. Generally BFS limits the maximal depth

% =N of every step. This is like doors opening every N step. When current length % is <KN, then search acts in width. K Is a step #. When k=N, then door

% opens and search jumps to the next step/brunch.

% The total search limit , limits the depth relatively to the first step only.

J=I.

% General move

move(L1,L2):-move_left(L1,L2).

move(L1,L2):-move_right(L1,L2).

move(L1,L2):-move_up(L1,L2).

move(L1,L2):-move_down(L1,L2).

% Elementary step. Linear representation of plain 3x3 move

move_left([0,A,B|T],[A,0,B|T]):-!.

move_left([A,0,B|T],[A,B,0|T]):-!.

move_left([A,B,C|T],[A,B,C|T1]):-!,move_left(T,T1),!.

move_right([A,B,0|T],[A,0,B|T]):-!.

move_right([A,0,B|T],[0,A,B|T]):-!.

move_right([A,B,C|T],[A,B,C|T1]):-!,move_right(T,T1),!.

move_up([0,A,B,C|T],[C,A,B,0|T]):-!.

move_up([H|T],[H|T1]):-!,move_up(T,T1),!.

move_down([A,B,C,0|T],[0,B,C,A|T]):-!.

move_down([H|T],[H|T1]):-!,move_down(T,T1),!.

% General output

out(L):-invord(L,[],L1),writepuz(L1,0),!.

% write total search list

writepuz([]_):-!.

writepuz([H|T],N):-!,N1=N+1,write(“Step #”,nl,write(H),nl,writepuz(T,N1),!.

% write one move in 3x3 plain form

writel([]):-!.

writel([A,B,C|T]):-!,write(A,B,C),nl,write(T),!.

% member element of list

member(M,[M|_]):-!.

member(M,[_|T]):-!,member(M,T),!.

% inverse order òf list

invord([],L,L):-!.

invord([H|T],T1,L):-!,invord(T,[H|T1],L),!.


L=[1,0,2,3,4,5,6,7,8],

puzzle(L,[L],0,100,20).

% 0-initial step, 100-totalsteps limit, 20-BFS limit , L-initial position, [L]-initiaL

% list of search————————————————

% END OF PROJECT PUZZLE 8 ————————————————————
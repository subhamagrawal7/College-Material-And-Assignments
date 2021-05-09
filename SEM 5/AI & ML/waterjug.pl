min(X,Y,X):-X<Y,!.
min(_,Y,Y).

rev(L,R):-revacc(L,[],R).
revacc([],R,R):-!.
revacc([H|T],A,R):-revacc(T,[H|A],R).

%Solve water jug problem using DFS
%X,Y are initial contents, Nx,Ny are final contents of jug1 of capacity _ and jug2 of capacity My respectively after pouring from jug1 into jug2
chk(_,X,My,Y,Nx,Ny):-	X>0,Y<My,Ey is My-Y,min(X,Ey,P),
			Nx is X-P,Ny is Y+P.
%Given 3 jugs of capacities Mx,My,Mz and filled with X,Y,Z units of a liquid respectively,give steps so that finally they contain Fx,Fy,Fz units of the liquid respectively.
jug(Mx,My,Mz,X,Y,Z,Fx,Fy,Fz):-jug(Mx,X,My,Y,Mz,Z,Fx,Fy,Fz,[],['Initially']).

jug(_,Fx,_,Fy,_,Fz,Fx,Fy,Fz,T,R):-!,rev([[Fx,Fy,Fz],[Fx,Fy,Fz]|T],TR),rev(['Finally'|R],RR),display(TR,RR).
jug(Mx,X,My,Y,Mz,Z,Fx,Fy,Fz,T,R):-chk(Mx,X,My,Y,Nx,Ny),not(member([Nx,Ny,Z],T))				,jug(Mx,Nx,My,Ny,Mz,Z,Fx,Fy,Fz,[[X,Y,Z]|T],['Pour liquid from jug1 into jug2'|R]).
jug(Mx,X,My,Y,Mz,Z,Fx,Fy,Fz,T,R):-chk(Mx,X,Mz,Z,Nx,Nz),not(member([Nx,Y,Nz],T))				,jug(Mx,Nx,My,Y,Mz,Nz,Fx,Fy,Fz,[[X,Y,Z]|T],['Pour liquid from jug1 into jug3'|R]).
jug(Mx,X,My,Y,Mz,Z,Fx,Fy,Fz,T,R):-chk(My,Y,Mz,Z,Ny,Nz),not(member([X,Ny,Nz],T))				,jug(Mx,X,My,Ny,Mz,Nz,Fx,Fy,Fz,[[X,Y,Z]|T],['Pour liquid from jug2 into jug3'|R]).
jug(Mx,X,My,Y,Mz,Z,Fx,Fy,Fz,T,R):-chk(My,Y,Mx,X,Ny,Nx),not(member([Nx,Ny,Z],T))				,jug(Mx,Nx,My,Ny,Mz,Z,Fx,Fy,Fz,[[X,Y,Z]|T],['Pour liquid from jug2 into jug1'|R]).
jug(Mx,X,My,Y,Mz,Z,Fx,Fy,Fz,T,R):-chk(Mz,Z,Mx,X,Nz,Nx),not(member([Nx,Y,Nz],T))				,jug(Mx,Nx,My,Y,Mz,Nz,Fx,Fy,Fz,[[X,Y,Z]|T],['Pour liquid from jug3 into jug1'|R]).
jug(Mx,X,My,Y,Mz,Z,Fx,Fy,Fz,T,R):-chk(Mz,Z,My,Y,Nz,Ny),not(member([X,Ny,Nz],T))				,jug(Mx,X,My,Ny,Mz,Nz,Fx,Fy,Fz,[[X,Y,Z]|T],['Pour liquid from jug3 into jug2'|R]).

display([],[]):-!.
display([T1|T],[R1|R]):-write(R1),write(' : '),write(T1),nl,display(T,R).


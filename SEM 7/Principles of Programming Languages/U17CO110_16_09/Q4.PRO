domains
    file = op
    list = string*
predicates
    start
    reading(string,string)
    replace(string,string,list,list)
    concatstr(string,char,string)
    str_list(string,list)
    list_str(list,string,string)

clauses
    start:-    
    readdevice(keyboard),
    write("Enter Word to be Replaced: "),nl,
    readln(W),
    write("Enter Replacement: "),nl,
    readln(A),
    openread(op,"input1.txt"),readdevice(op),reading("",Input),
    str_list(Input,L),
    replace(W,A,L,Z),
    list_str(Z,"",S),
    write(S),
    openwrite(op,"input1.txt"),writedevice(op),write(S),closefile(op).
       
    reading(S,Input):-
    not(eof(op)),!,
    readchar(X),
    concatstr(S,X,ST),
    reading(ST,Input).
     
    reading(S,Input):-
    Input=S,
    closefile(op).
    
    replace(_,_,[],[]).
    replace(X,Y,[H|T],[Y|P]) :- H=X,!,replace(X,Y,T,P).
    replace(X,Y,[H|T],[H|P]) :- replace(X,Y,T,P).
    
    concatstr(S,X,ST):-
    str_char(Z,X),
    concat(S,Z,ST).
    
    str_list(S,[H|T]):-
    fronttoken(S,H,S1),!,
    str_list(S1,T).
    str_list(_,[]).
	
     
    list_str([],ST,ST).
    list_str([H|T],ST,S):-
    concat(ST,H,A),
    concat(A," ",Z),
    list_str(T,Z,S).
     
     
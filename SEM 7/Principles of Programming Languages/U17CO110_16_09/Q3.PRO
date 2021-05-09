domains
    file = op
    list = string*
predicates
    start
    reading(string,string)
    concatstr(string,char,string)
    str_list(string,list)
    list_str(list,string,string)
    insert(string,integer,list,list)
    
clauses
    start:-    
    readdevice(keyboard),
    write("ENTER THE WORD YOU WANT TO INSERT "),nl,
    readln(W),
    write("ENTER THE POSITION "),nl,
    readint(N),
    openread(op,"input.txt"),readdevice(op),reading("",Input),
    str_list(Input,L),
    insert(W,N,L,Z),
    list_str(Z,"",S),
    write(S),
    openwrite(op,"input.txt"),writedevice(op),write(S),closefile(op).
    
    reading(S,Input):-
    not(eof(op)),!,
    readchar(X),
    concatstr(S,X,ST),
    reading(ST,Input).
     
    reading(S,Input):-
    Input=S,
    closefile(op).
    
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
    
	insert(_,N,[],_):-N>1,write("No position Found!"),nl,!.
    insert(W,1,[H|T],[W|TL]):-H=W,!,TL=T. 
    insert(W,1,X,[W|X]). 
    insert(W,N,[H|T],[H|TL]):-N>1,NL=N-1,insert(W,NL,T,TL).    
      
       

domains
    list=symbol*
predicates
    del(symbol,list,list)
clauses
    del(X,[X|Tail],Tail).
    
    del(X,[Y|Tail],[Y|Tail1]):-
        del(X,Tail,Tail1).
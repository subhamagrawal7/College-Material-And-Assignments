domains
    x = integer
    l = integer*

predicates
    countOccurence(x,l,x)

clauses
    countOccurence(Element,[],0).

    countOccurence(Element,[X|List],OccurNum) :-
        Element = X,!,
        countOccurence(Element,List,OccurNum1),
        OccurNum = OccurNum1 + 1.

    countOccurence(Element,[X|List],OccurNum) :-
        countOccurence(Element,List,OccurNum).
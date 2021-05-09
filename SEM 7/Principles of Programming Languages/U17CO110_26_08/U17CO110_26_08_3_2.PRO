domains
    integerList = integer*

predicates
    ordered(integerList)

clauses
    ordered([]).
    ordered([_]).
    ordered([H1,H2| Tail]):- H1 <= H2, ordered([H2|Tail]).
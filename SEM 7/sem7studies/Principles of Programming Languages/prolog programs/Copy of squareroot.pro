predicates
	on_top_of(symbol, symbol)
	above(symbol,symbol)
clauses
	
on_top_of(prolog_book, desk).
on_top_of(ai_notes, prolog_book).
on_top_of(time_table, ai_notes).
on_top_of(ai_book, desk).

above(X,Y) :- on_top_of(X,Y).
above(X,Y) :- on_top_of(X,Z),
	      above(Z,Y).
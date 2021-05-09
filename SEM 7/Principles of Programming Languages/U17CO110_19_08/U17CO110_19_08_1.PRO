predicates
    find_roots(real, real, real)
    type_of_root(real,real,real)
clauses
    find_roots(A,B,C):- D = B*B - 4*A*C, type_of_root(A,B,D).
    type_of_root(A,B,D):- D < 0, 
                          write("The roots of the equation are imaginary."), nl,
                          T = -D,
                          Z = sqrt(T),
                          X = -B/(2*A),
                          Y = Z/(2*A),
                          write("The roots of the equation are ", X, "+i", Y),nl,
                          write("and ", X, "-i", Y),nl.
    type_of_root(A,B,D):- D = 0, 
                          X = -B/(2*A), 
                          write("The roots are real and equal, they are X = ", X), nl.
    type_of_root(A,B,D):- D > 0, 
                          Z = sqrt(D), 
                          X1 = (-B + Z)/(2*A), 
                          X2 = (-B - Z)/(2*A),
                          write("The roots are real and unequal"),nl,
                          write("The first root is ", X1),nl,
                          write("The second root is ", X2),nl.
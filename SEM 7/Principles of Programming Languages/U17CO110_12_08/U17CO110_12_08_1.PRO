predicates

    male(symbol).
    female(symbol).
    father(symbol,symbol).
    husband(symbol,symbol).
    brother(symbol,symbol).
    sister(symbol,symbol).
    mother(symbol,symbol).
    grandfather(symbol).
    grandmother(symbol).
    uncle(symbol).
    aunt(symbol).
    cousin(symbol).
	nephew(symbol,symbol).
	niece(symbol,symbol).
	motherLaw(symbol,symbol).
	fatherLaw(symbol,symbol).
    
clauses

    male(amitabh).
    male(harivansh).
    male(abhishek).
    male(nikhil).
    male(ajitabh).
    
    female(jaya).
    female(shyama).
    female(shweta).
    female(aishwarya).
    female(aaradhya).
   
    father(amitabh,abhishek).
    father(harivansh,amitabh).
    father(abhishek,aaradhya).
    father(harivansh,ajitabh).
    father(amitabh,shweta).
    
    husband(amitabh,jaya).
    husband(harivansh,shyama).
    husband(abhishek,aishwarya).
    husband(nikhil,shewta).
    
    mother(X,Y):- husband(Z,X),
            father(Z,Y).
    
    brother(X,Y):- father(Z,X),
            father(Z,Y),
            X<>Y,
            male(X).
            
    sister(X,Y):- father(Z,X),
            father(Z,Y),
            X<>Y,
            female(X).
            
    
    grandfather(X):- father(Y, Z), 
                father(Z,X),
                write(Y, " is the grandfather of ",X,"\n").
                
    grandmother(X):- husband(Z,X),
                father(Z,V),
                father(V,Y),
                write(Y, " is the grandmother of ",X,"\n").
                

   uncle(X):- brother(Z,Y),
            father(Z,X),
            male(Y),
            write(Y,"\n"),
            fail.
    
    aunt(X):- husband(Z,Y),
            brother(Z,V),
            father(V,X),
            write(Y,"\n"),
            fail.
            
    cousin(X):- father(Z,X),
            father(V,Y),
            Z<>V,
            brother(V,Z),
            write(Y,"\n").
	
	nephew(X,Y):- male(X),
			father(Z,X),
			brother(Z,Y);
			male(X),
			father(Z,X),
			sister(Z,Y).
	niece(X,Y):- female(X),
			father(Z,X),
			brother(Z,Y);
			female(X),
			father(Z,X),
			sister(Z,Y).
	motherLaw(X,Y):- husband(Y,Z),
					mother(X,Z);
					husband(Z,Y),
					mother(X,Z).
	fatherLaw(X,Y):- husband(Y,Z),
					father(X,Z);
					husband(Z,Y),
					father(X,Z).			
trace
domains	
	num1,num2,maxnum= integer
predicates
	nums(num1,num2,maxnum)
clauses
	nums(X,Y,Z):-X>Y,!,X=Z.
	nums(X,Y,Z):-X<Y,Y=Z.

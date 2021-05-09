database
employee(string,integer,string,string,integer,string)

predicates
add
remove
find_salary
run
salary_class(string,Real)

clauses

run:-
retractall(employee(_,_,_,_,_,_)),
assertz(employee("A",101,"Accounts","Asst Manager",34,"B")),
assertz(employee("B",102,"Accounts","Manager",40,"A")),
assertz(employee("C",103,"Accounts","Field Officer",27,"C")),
fail.

run:-
write("I am ready with the database "),nl,
write("You may now type goals like add,remove,find_salary" ),nl,
exit.
add:-
write("ENTER NAME OF EMPLOYEE: "),nl,
        readln(EMP),
       write("ENTER EMPLOYEE CODE: "),nl,
        readint(EMPCODE),
       write("ENTER EMPLOYEE DEPT: "),nl,
        readln(EMPDEPT),
       write("ENTER EMPLOYEE DESIGNATION: "),nl,
        readln(EMPDES),
       write("ENTER EMPLOYEE AGE: "),nl,
        readint(EMPAGE),
       write("ENTER EMPLOYEE SALARY CLASS: "),nl,
        readln(EMPCLASS),nl,
		write("EMPLOYEE SUCCESSFULLY ADDED"),
       assertz(employee(EMP,EMPCODE,EMPDEPT,EMPDES,EMPAGE,EMPCLASS)).
        
remove:- write("ENTER EMPLOYEE CODE"),nl,
readint(A),
retract(employee(_,A,_,_,_,_)).

find_salary:-
write("ENTER EMPLOYEE CODE"),nl,
readint(A),
employee(_,A,_,_,_,Y),
salary_class(Y,Z),
X= Z+ Z*0.15,
write("TOTAL SALARY IS ",X),nl.

salary_class("A",35000).
salary_class("B",25000).
salary_class("C",15000).



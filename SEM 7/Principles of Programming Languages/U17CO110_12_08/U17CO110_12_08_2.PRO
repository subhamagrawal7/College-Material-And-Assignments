domains
disease, patient, indication =symbol

predicates
hypothesis(patient,disease)
symptom(patient,indication)
response(char)
go

clauses

go:-
write("What is the patient's name? "),
readln(Patient),
hypothesis(Patient, Disease),
write(Patient," Probably has ", Disease,"."),nl.

go:-
write("Sorry, I don't seem to be able to"), nl,
write("diagnose the disease."),nl,
write("Do you want to diagnose yourself(y/n)?"),
response(Reply),
Reply='y',
go.

symptom(Patient,fever):-
write("Does ",Patient, "have a fever(y/n)?"),
response(Reply),
Reply='y'.

symptom(Patient,rash):-
write("Does ",Patient, "have a rash(y/n)?"),
response(Reply),
Reply='y'.

symptom(Patient,headache):-
write("Does ",Patient, "have a headache(y/n)?"),
response(Reply),
Reply='y'.

symptom(Patient,runny_nose):-
write("Does ",Patient, "have a runny_nose(y/n)?"),
response(Reply),
Reply='y'.

symptom(Patient,conjunctivitis):-
write("Does ",Patient, "have a conjunctivitis(y/n)?"),
response(Reply),
Reply='y'.

symptom(Patient,cough):-
write("Does ",Patient, "have a cough(y/n)?"),
response(Reply),
Reply='y'.

symptom(Patient,body_ache):-
write("Does ",Patient, "have a body ache(y/n)?"),
response(Reply),
Reply='y'.

symptom(Patient,chills):-
write("Does ",Patient, "have a chills(y/n)?"),
response(Reply),
Reply='y'.

symptom(Patient,sore_throat):-
write("Does ",Patient, "have a sore throat(y/n)?"),
response(Reply),
Reply='y'.

symptom(Patient,sneezing):-
write("Is ",Patient, " sneezing(y/n)?"),
response(Reply),
Reply='y'.

symptom(Patient,swollen_glands):-
write("Does ",Patient, "have a swollen_glands(y/n)?"),
response(Reply),
Reply='y'.

hypothesis(Patient,measles):-
symptom(Patient,fever),
symptom(Patient,cough),
symptom(Patient,conjunctivitis),
symptom(Patient,runny_nose),
symptom(Patient,rash).

hypothesis(Patient,german_measles):-
symptom(Patient,fever),
symptom(Patient,headache),
symptom(Patient,runny_nose),
symptom(Patient,rash).

hypothesis(Patient,flu):-
symptom(Patient,fever),
symptom(Patient,headache),
symptom(Patient,body_ache),
symptom(Patient,conjunctivitis),
symptom(Patient,chills),
symptom(Patient,sore_throat),
symptom(Patient,cough),
symptom(Patient,runny_nose).

hypothesis(Patient,common_cold):-
symptom(Patient,headache),
symptom(Patient,sneezing),
symptom(Patient,sore_throat),
symptom(Patient,chills),
symptom(Patient,runny_nose).

hypothesis(Patient,mumps):-
symptom(Patient,fever),
symptom(Patient,swollen_glands).

hypothesis(Patient,chicken_pox):-
symptom(Patient,fever),
symptom(Patient,rash),
symptom(Patient,body_ache),
symptom(Patient,chills).

hypothesis(Patient,whooping_cough):-
symptom(Patient,cough),
symptom(Patient,sneezing),
symptom(Patient,runny_nose).

response(Reply):-
readchar(Reply),
write(Reply),nl.

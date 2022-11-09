% CS3210 - Principles of Programming Languages - Fall 2022
% Instructor: Thyago Mota
% Description: Homework 10 - A KB in Prolog with queries
% Student Name: Erik Sundblad
certifiedClimber(john).
certifiedClimber(kelly).
certifiedClimber(maria).
certifiedClimber(derek).
not(certifiedClimber(thyago)).

mountain(everest).
mountain(aconcagua).
mountain(mcKinley).
mountain(kilimanjaro).
mountain(elbrus).
mountain(vinson).
mountain(puncakJaya).

continent(southAmerica).
continent(northAmerica).
continent(asia).
continent(africa).
continent(antarctica).
continent(europe).
continent(australia).

height(everest, 29029) :- mountain(everest).
height(aconcagua, 22841) :- mountain(aconcagua).
height(mcKinley, 20312) :- mountain(mcKinley).
height(kilimanjaro, 19340) :- mountain(kilimanjaro).
height(elbrus, 18510) :- mountain(elbrus).
height(vinson, 16050) :- mountain(vinson).
height(puncakJaya, 16023) :- mountain(puncakJaya).

located(everest, asia) :- mountain(everest),continent(asia).
located(aconcagua, southAmerica) :- mountain(aconcagua),continent(southAmerica).
located(mcKinley, northAmerica) :- mountain(mcKinley),continent(northAmerica).
located(kilimanjaro, africa) :- mountain(kilimanjaro),continent(africa).
located(elbrus, europe) :- mountain(elbrus),continent(europe).
located(vinson, antarctica) :- mountain(vinson),continent(antarctica).
located(puncakJaya, australia) :- mountain(puncakJaya),continent(australia).


wouldClimb(john, Mtn) :- certifiedClimber(john),located(Mtn, northAmerica).
wouldClimb(kelly, Mtn) :- certifiedClimber(kelly), height(Mtn, X), X>= 20000.
wouldClimb(maria, Mtn) :- certifiedClimber(maria), mountain(Mtn).
wouldClimb(derek, Mtn) :- certifiedClimber(derek), (located(Mtn, europe); located(Mtn, africa); located(Mtn, australia)), height(Mtn, X), X =< 19000.
wouldClimb(thyago, Mtn) :- not(certifiedClimber(thyago)), not(mountain(Mtn)).

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%Queries%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% mountain(everest).
% located(kilimanjaro, africa).
% (height(elbrus, X), X > 18000).
% certifiedClimber(thyago).
% certifiedClimber(X).
% wouldClimb(john, X).
% wouldClimb(kelly, X).
% wouldClimb(maria, X).
% wouldClimb(derek, X).
% wouldClimb(thyago, X).

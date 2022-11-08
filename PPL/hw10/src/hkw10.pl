% CS3210 - Principles of Programming Languages - Fall 2022
% Instructor: Thyago Mota
% Description: Homework 10 - A KB in Prolog with queries
% Student Name: Erik Sundblad
2certifiedClimber(john).
certifiedClimber(kelly).
certifiedClimber(maria).
certifiedClimber(derek).

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

height(everest, 29029) :- mountain(everst).
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


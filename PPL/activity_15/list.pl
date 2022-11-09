twice([],[]).
twice([X|T1], [X,X | T2]) :- twice(T1, T2).

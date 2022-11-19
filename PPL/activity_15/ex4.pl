swap(_, _, [], []).
swap(X, Y, [X|T], [Y|T2]) :- swap(X, Y, T, T2).
swap(X, Y, [B|T], [B|T2]) :- swap(X, Y, T, T2).
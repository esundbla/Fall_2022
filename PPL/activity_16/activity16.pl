:- dynamic married/2.

is_true(Q) :-
    format('~w?~n', Q),
    read(yes).

married(jhon,mary).
married(mary,jhon).

marry(X, Y) :-
    (not(married(X, _)),not(married(Y, _))),
    (not(married(_, X)),not(married(_, Y))),
    is_true('Are you sure'),
    is_true('100% sure'),
    assert(married(X,Y)),
    assert(married(Y,X)),
    writeln('Congrats!').

divorce(X,Y) :-
    (married(X,Y)),
    is_true('They are done?'),
    retract(married(X,Y)),
    retract(married(Y,X)),
    writeln('Its done').




    
    

    

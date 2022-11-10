factorial(0, 1).
factorial(X, Y) :- X > 0, X_dec is X-1 ,factorial(X_dec, Z), Y is X * Z.
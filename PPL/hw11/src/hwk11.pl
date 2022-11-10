sum([], 0).                                                 %Sum base case of empty
sum([X|T], Z) :- sum(T, Y), Z  is X + Y.                    %Recursive call adding results

max([X|[]], X).                                             %Base case set of 1 return 1
max([X1,X2|T], Z) :- X1 >= X2,   max([X1|T], F), Z is F.    %Case of greater than or equals
max([X1,X2|T], Z) :- X1 < X2,   max([X2|T], F), Z is F.     %Casse of less than 

%______________Tests________________________%

%1 ?- sum([],0).
%true.

%2 ?- sum([1, 2, 5], 8).
%true.

%3 ?- sum([1, 2, 5], X). 
%X = 8.

%4 ?- max([1, 2, 5], 5).
%true

%5 ?- max([1, 2, 5], X). 
%X = 5
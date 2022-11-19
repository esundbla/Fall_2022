% CS3210 - Principles of Programming Languages - Fall 2022
% Instructor: Thyago Mota
% Description: Fruits of the world
% Student(s) Name(s): Erik Sundblad

:- dynamic fact/1.
:- dynamic opt/2.

is_true(Question) :-
  (
    fact(Question) ->
      true; fact(not(Question)) -> false;
      format('~w?~n', [Question]),
      Answer = read(yes),
      ( Answer -> assert(fact(Question)); assert(fact(not(Question))), false)
  ).


member(X, [X | _]).
member(X, [_ | T]) :-member(X, T).

is_option(Question, Options) :-
  (
    opt(Question, Options) ->
      true; opt(not(Question), Options) -> false;
      format('~w?~n', [Question]),
      read(Answer),
      ( member(Answer, Options) -> assert(opt(Question, Options)); assert(opt(not(Question), Options)), false )
  ).

fruit(pinnaple) :- not(is_true('is Speherical')), is_true('is Spikey').
fruit(bannana) :- not(is_true('is Speherical')), not(is_true('is Spikey')).
fruit(coconut) :- is_true('is Speherical'), is_true('is Fuzzy'), is_true('is Big').
fruit(kiwi) :- is_true('is Speherical'), is_true('is Fuzzy'), not(is_true('is Big')).
fruit(tomato) :- is_true('is Speherical'), not(is_true('is Sweet')), is_true('is Red').
fruit(tomatillo) :- is_true('is Speherical'), not(is_true('is Sweet')), not(is_true('is Red')).
fruit(lemon) :- is_true('is Speherical'), not(is_true('is Sweet')), is_true('is Citrus'), is_true('is Big').
fruit(orange) :- is_true('is Speherical'), is_true('is Sweet'), is_true('is Citrus'), is_true('is Big').
fruit(clementine) :- is_true('is Speherical'), is_true('is Sweet'), is_true('is Citrus'), not(is_true('is Big')).
fruit(cherry) :- is_true('is Speherical'), is_true('is Sweet'), is_true('is Stonefruit'), is_true('is Small').
fruit(plum) :- is_true('is Speherical'), is_true('is Sweet'), is_true('is Stonefruit'), not(is_true('is Small')), is_true('is Purple').
fruit(apricot) :- is_true('is Speherical'), is_true('is Sweet'), is_true('is Stonefruit'), not(is_true('is Small')), not(is_true('is Purple')).
fruit(apple) :- is_true('is Speherical'), is_true('is Sweet'), not(is_true('grows on vine')).
fruit(melon) :- is_true('is Speherical'), is_true('is Sweet'), is_option('what is the color of the flesh', [green, orange]).
fruit(grape) :- is_true('is Speherical'), is_true('is Sweet'), not(is_option('what is the color of the flesh', [green, orange])).


begin :- format('Welcome to fruits of the world~nI will try to geuse the fruit you are thinking of through questions~nPLease answer yes. or no.~n'),
         is_true('Ready'),
         ( fruit(A) -> format('I think your fruit is a ~w.~n', [A]); false ),
         (is_true('Is this the right fruit') -> format('Nice enjoy that ~w.~nFeel free to play again just type begin.', [A]); format('No way! My mistake ~nWell feel free to play again simply type begin.')),
         retractall(fact(_)), retractall(opt(_,_)).
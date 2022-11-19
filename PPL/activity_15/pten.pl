pten(um,one). 
pten(dois,two). 
pten(tres,three). 
pten(quatro,four). 
pten(cinco,five). 
pten(seis,six). 
pten(sete,seven). 
pten(oito,eight). 
pten(nove,nine). 
pten(dez,ten).

listpen([],[]).
listpen([P|T], [E|T2] ) :- pten(P,E), listpen(T, T2).


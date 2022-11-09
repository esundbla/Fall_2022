elf(bing). 
elf(penny). 
elf('Gabriel'). 
elf(trixie). 
wizard(merlin). 
wizard(gandalf). 
witch(jadis). 
magic(X) :- elf(X). 
magic(X) :- wizard(X). 
magic(X) :- witch(X). 
freeze(X,Y) :- wizard(X), elf(Y).
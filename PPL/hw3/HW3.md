# Formal Grammars

For each of the grammars from Q1-3, classify them as either regular or context-free. Then answer yes/no whether each word can be generated from the grammar. If you answer yes, show the sequence of productions to generate the word.  When you are done, submit this README.md file with your answers on Canvas. 

## Q1

Regular Grammer
```
G = (V, T, P, S) 
V = {S, NP, NOM, VP, Det, Noun, Verb, Aux}
T = {that, this, a, the, man, book, flight, meal, include, read, does}
P = {
    S → NP VP 
    S → Aux NP VP 
    S → VP 
    NP → Det NOM 
    NOM → Noun
    NOM → Noun NOM
    VP → Verb
    VP → Verb NP
    Det → that | this | a | the
    Noun → book | flight | meal | man
    Verb → book | include | read
    Aux → does
} 
```

### a)
Yes
S ->
Aux NP VP ->
does NP VP ->
does Det NOM VP ->
does a NOM VP ->
does a Noun VP ->
does a meal VP ->
does a meal Verb NP ->
does a meal include NP ->
does a meal include Det NOM ->
does a meal include a NOM ->
does a meal include a Noun ->
does a meal include a book 

```
does a meal include a book 
```

### b)
Yes 
S ->
NP VP ->
Det NOM VP ->
this NOM VP ->
this Noun VP ->
this flight VP ->
this flight Verb NP ->
this flight book NP ->
this flight book Det NOM ->
this flight book a NOM ->
this flight book a Noun ->
this flight book a meal 
```
this flight book a meal
``` 

### c) 
Yes
S ->
NP VP ->
Det NOM VP ->
a NOM VP ->
a noun VP ->
a man VP ->
a man Verb NP ->
a man read NP ->
a man read Det NOM ->
a man read a NOM ->
a man read a Noun ->
a man read a book
```
a man read a book
```

## Q2
Regular Gramer
```
G = ({S, A, B}, {a, b}, P, S) 
P = {S → aA, A → bB | ε, B → aA}    
```

### a) 
Yes
S ->
aA ->
a
```
a
```

### b) 
Yes
S ->
aA ->
abB ->
abaA ->
aba
```
aba
```

### c) 
No
```
bb
```

### d) 
No
```
abb
```

## Q3
Regular
```
G = ({S, A}, {0, 1}, P, S) 
P = {S → A0, A→A01|ε}           
```
 
### a) 
No
```
00
```
 
### b) 
No
```
ε
```

### c)
Yes
S ->
A0 ->
A010 ->
010
```
010
```
 
### d) 
Yes
S -> 
A0 -> 
A010 ->
A01010 ->
A0101010 ->
0101010
```
0101010
```
 
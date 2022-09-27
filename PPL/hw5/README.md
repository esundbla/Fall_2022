# Left Recursion Elimination

Eliminate any left-recursive productions (including indirect ones). When you are done, submit this README.md file with your answers on Canvas. 

## Q1

```
X -> XYz | Xw | w
Y -> Yp | q
```
X  -> wX' 
X' -> YzX' | wX' | epsilon
Y  -> qY'
Y' -> pY' | epsilon

## Q2

```
S -> aA | Sd
A -> b
```
S  -> aAS'
S' -> dS' | epsilon
A  -> b

## Q3

```
A -> Bxy | x            ``` A -> ADxy | cDxy | x
B -> CD
C -> A | c
D -> d           
```
A  -> cDxyA' | xA' 
A' -> DxyA' | epsilon
B -> CD
C -> A | c
D -> d
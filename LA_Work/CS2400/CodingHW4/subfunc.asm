#Subfunc for homework 4
#CS2400 Fall 2022
#Erik Sundblad

.text
.globl subfunc
subfunc:
	add $v0, $a1, $a1	#v= x+x
	jr $ra			#return(v)

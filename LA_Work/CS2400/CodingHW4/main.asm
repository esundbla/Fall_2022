#Assignment four demo code
#CS2400 Fall 2022
#Erik Sundblad
.data
	before: .asciiz "Value of x before subfunc is: "
	after: .asciiz "\nValue of x after subfunc is: "

.text
.globl main
main:
	addi $t0, $t0, 2	#int x=2
	
	la $a0, before
	li $v0, 4
	syscall		#print before string
	
	la $a0, ($t0)
	li $v0, 1
	syscall 	#print value of X
	
	move $a1, $t0   #Move x into passable register "first four arguments"
	jal subfunc	#execute subfunc
	
	move $t0, $v0	#get value post function
	
	la $a0, after
	li $v0, 4
	syscall		#print after string
	
	la $a0, ($t0)
	li $v0, 1
	syscall 	#print value of X
	
	li $v0, 10
	syscall		#exit()
	

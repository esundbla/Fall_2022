.data
	array: .word 1, -2, 3, -22, -24, 1, 5, -8, 7, -7, 6, -4 # 12 elements long
	output: .asciiz "The count of negative elements converted is equal to: "
.text
	li $s0, 0 #loop counter
	li $s1, 0 #negative element counter
	
	#######################YOUR CODE HERE#########################
	
	
	
	la $a0, output
	li $v0, 4
	syscall
	
	move $a0, $s1
	li $v0, 1
	syscall 
	
	
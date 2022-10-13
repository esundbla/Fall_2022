.data
	arr_1: .word 10, 2, 3, 7, 8, 4, -4, 3
	arr_2: .word 1 , 8, 15,3,-4, 7,  3, -1	
	space: .asciiz " "
.text
	li $t0, -4
	
loop:
	addi $t0, $t0, 4
	lw $t1, arr_1($t0)
	lw $t2, arr_2($t0)
	
	mul $t4, $t1, $t2
	
	move $a0, $t4
	li $v0, 1
	syscall
	
	la $a0, space
	li $v0, 4
	syscall
	
	bne $t0, 28, loop
	
	li $v0 10
	syscall
	
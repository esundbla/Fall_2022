# File to hold code segments for mid-term 
# Erik Sundblad
# CS2400 

.data
	grt: .asciiz "Greater than"
	lst: .asciiz "Less than"
	
.text
	li $t0, 1	#x
	la $t1,($0)	#y
	li $t3, 7	#z
	
	mul $t4, $t3, $t1
	
	bgt $t4, $t0, greater
	
	la $a0, lst
	li $v0, 4
	syscall
	j end
greater: 
	la $a0, grt
	li $v0, 4
	syscall
end:	
	li $v0, 10	#exit()
	syscall
	
	
	
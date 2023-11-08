rsum:
	andq %rsi, %rsi
	jle end
	pushq %rbx
	mrmovq (%rdi), %rbx		# get *start
	irmovq $-1, %r10
	irmovq $8, %r11
	addq %r10, %rsi
	addq %r11, %rdi 
	call rsum
	addq %rbx, %rax
	popq %rbx
	ret
end:
	movl $0, %eax
	ret

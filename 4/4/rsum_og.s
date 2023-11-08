rsum:	# start in rdi, count in rsi
	testq	%rsi, %rsi
	jle	.L3
	pushq	%rbx
	movq	(%rdi), %rbx
	subq	$1, %rsi
	addq	$8, %rdi
	call	rsum
	addq	%rbx, %rax
	popq	%rbx
	ret
.L3:	# if(count <= 0)
	movl	$0, %eax
	ret
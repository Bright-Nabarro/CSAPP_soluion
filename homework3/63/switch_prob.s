	.file	"switch_prob.c"
	.text
	.globl	switch_prob
	.type	switch_prob, @function
switch_prob:
.LFB0:
	.cfi_startproc
	subq	$60, %rsi
	cmpq	$5, %rsi
	ja	.L2
	leaq	.L4(%rip), %rdx
	movslq	(%rdx,%rsi,4), %rax
	addq	%rdx, %rax
	jmp	*%rax
	.section	.rodata
	.align 4
	.align 4
.L4:
	.long	.L7-.L4
	.long	.L2-.L4
	.long	.L7-.L4
	.long	.L6-.L4
	.long	.L5-.L4
	.long	.L3-.L4
	.text
.L7:
	leaq	0(,%rdi,8), %rax
	ret
.L6:
	leaq	7(%rdi), %rax
	testq	%rdi, %rdi
	cmovs	%rax, %rdi
	movq	%rdi, %rax
	sarq	$3, %rax
	ret
.L5:
	leaq	(%rdi,%rdi,2), %rdi
.L3:
	imulq	%rdi, %rdi
.L2:
	leaq	75(%rdi), %rax
	ret
	.cfi_endproc
.LFE0:
	.size	switch_prob, .-switch_prob
	.ident	"GCC: (GNU) 13.2.1 20230801"
	.section	.note.GNU-stack,"",@progbits

	.file	"transpose.c"
	.text
	.globl	transpose
	.type	transpose, @function
transpose:
.LFB0:
	.cfi_startproc
	leaq	1800(%rdi), %r8
	leaq	1920(%rdi), %r9
.L2:
	leaq	-1800(%r8), %rax
	movq	%rdi, %rdx
.L3:
	movq	(%rdx), %rcx
	movq	(%rax), %rsi
	movq	%rsi, (%rdx)
	movq	%rcx, (%rax)
	addq	$8, %rdx
	addq	$120, %rax
	cmpq	%r8, %rax
	jne	.L3
	addq	$120, %rdi
	addq	$8, %r8
	cmpq	%r9, %r8
	jne	.L2
	ret
	.cfi_endproc
.LFE0:
	.size	transpose, .-transpose
	.ident	"GCC: (GNU) 13.2.1 20230801"
	.section	.note.GNU-stack,"",@progbits

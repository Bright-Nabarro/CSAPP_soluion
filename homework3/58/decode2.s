	.file	"decode2.c"
	.text
	.globl	decode2
	.type	decode2, @function
decode2:
.LFB0:
	.cfi_startproc
	subq	%rdi, %rsi
	imulq	%rsi, %rdi
	movq	%rdi, %rax
	salq	$63, %rax
	sarq	$63, %rax
	xorq	%rdi, %rax
	ret
	.cfi_endproc
.LFE0:
	.size	decode2, .-decode2
	.ident	"GCC: (GNU) 13.2.1 20230801"
	.section	.note.GNU-stack,"",@progbits

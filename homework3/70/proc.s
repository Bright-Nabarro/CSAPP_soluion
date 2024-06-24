	.file	"proc.c"
	.text
	.globl	proc
	.type	proc, @function
proc:
.LFB0:
	.cfi_startproc
	movq	8(%rdi), %rdx
	movq	(%rdx), %rax
	movq	(%rax), %rax
	subq	8(%rdx), %rax
	movq	%rax, (%rdi)
	ret
	.cfi_endproc
.LFE0:
	.size	proc, .-proc
	.ident	"GCC: (GNU) 13.2.1 20230801"
	.section	.note.GNU-stack,"",@progbits

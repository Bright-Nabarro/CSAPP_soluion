	.file	"eval.c"
	.text
	.globl	process
	.type	process, @function
process:
.LFB0:
	.cfi_startproc
	movq	%rdi, %rax
	movq	16(%rsp), %rdx
	movq	%rdx, -40(%rsp)
	movq	8(%rsp), %rdx
	movq	%rdx, -32(%rsp)
	movq	24(%rsp), %rdx
	movq	(%rdx), %rdx
	movq	%rdx, -24(%rsp)
	movdqa	-40(%rsp), %xmm0
	movups	%xmm0, (%rdi)
	movq	%rdx, 16(%rdi)
	ret
	.cfi_endproc
.LFE0:
	.size	process, .-process
	.globl	eval
	.type	eval, @function
eval:
.LFB1:
	.cfi_startproc
	subq	$88, %rsp
	.cfi_def_cfa_offset 96
	movq	%rdx, 8(%rsp)
	movq	%rdi, 48(%rsp)
	movq	%rsi, 56(%rsp)
	leaq	8(%rsp), %rax
	movq	%rax, 64(%rsp)
	leaq	16(%rsp), %rdi
	subq	$32, %rsp
	.cfi_def_cfa_offset 128
	movdqa	80(%rsp), %xmm0
	movups	%xmm0, (%rsp)
	movq	%rax, 16(%rsp)
	call	process
	movq	56(%rsp), %rax
	addq	48(%rsp), %rax
	addq	64(%rsp), %rax
	addq	$120, %rsp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE1:
	.size	eval, .-eval
	.ident	"GCC: (GNU) 13.2.1 20230801"
	.section	.note.GNU-stack,"",@progbits

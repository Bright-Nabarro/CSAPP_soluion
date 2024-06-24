	.file	"sum_col.c"
	.text
	.globl	sum_col
	.type	sum_col, @function
sum_col:
.LFB0:
	.cfi_startproc
	leaq	1(,%rdi,4), %r9
	movl	$0, %ecx
	movl	$0, %eax
	jmp	.L2
.L3:
	movq	%rax, %r8
	imulq	%r9, %r8
	leaq	(%rsi,%r8,8), %r8
	addq	(%r8,%rdx,8), %rcx
	addq	$1, %rax
.L2:
	leaq	(%rdi,%rdi,2), %r8
	cmpq	%rax, %r8
	jg	.L3
	movq	%rcx, %rax
	ret
	.cfi_endproc
.LFE0:
	.size	sum_col, .-sum_col
	.ident	"GCC: (GNU) 13.2.1 20230801"
	.section	.note.GNU-stack,"",@progbits

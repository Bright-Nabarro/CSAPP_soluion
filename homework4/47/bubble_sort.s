	.file	"bubble_sort.c"
	.text
	.globl	bubble_sort
	.type	bubble_sort, @function
bubble_sort:
.LFB0:
	.cfi_startproc
	subq	$8, %rsi
	jmp	.L2
.L3:
	addq	$8, %rax
.L5:
	cmpq	%rsi, %rax
	je	.L7
	movq	8(%rax), %rdx
	movq	(%rax), %rcx
	cmpq	%rcx, %rdx
	jge	.L3
	movq	%rcx, 8(%rax)
	movq	%rdx, (%rax)
	jmp	.L3
.L7:
	subq	$8, %rsi
.L2:
	cmpq	%rdi, %rsi
	je	.L8
	movq	%rdi, %rax
	jmp	.L5
.L8:
	ret
	.cfi_endproc
.LFE0:
	.size	bubble_sort, .-bubble_sort
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	leaq	80+g_data(%rip), %rsi
	leaq	-80(%rsi), %rdi
	call	bubble_sort
	movl	$0, %eax
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.globl	g_data
	.data
	.align 32
	.type	g_data, @object
	.size	g_data, 80
g_data:
	.quad	10
	.quad	9
	.quad	8
	.quad	7
	.quad	6
	.quad	5
	.quad	4
	.quad	3
	.quad	2
	.quad	1
	.ident	"GCC: (GNU) 13.2.1 20230801"
	.section	.note.GNU-stack,"",@progbits

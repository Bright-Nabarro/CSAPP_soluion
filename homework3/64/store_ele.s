	.file	"store_ele.c"
	.text
	.globl	store_ele
	.type	store_ele, @function
store_ele:
.LFB0:
	.cfi_startproc
	movq	%rdx, %r8
	leaq	(%rsi,%rsi,2), %rax
	leaq	(%rsi,%rax,4), %rax
	movq	%rdi, %rdx
	salq	$6, %rdx
	addq	%rdi, %rdx
	leaq	(%rax,%rdx), %rdi
	addq	%r8, %rdi
	leaq	A(%rip), %rax
	movq	(%rax,%rdi,8), %rax
	movq	%rax, (%rcx)
	movl	$3640, %eax
	ret
	.cfi_endproc
.LFE0:
	.size	store_ele, .-store_ele
	.globl	A
	.bss
	.align 32
	.type	A, @object
	.size	A, 3640
A:
	.zero	3640
	.ident	"GCC: (GNU) 13.2.1 20230801"
	.section	.note.GNU-stack,"",@progbits

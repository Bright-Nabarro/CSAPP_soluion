	.file	"switch.c"
	.text
	.globl	switch1
	.type	switch1, @function
switch1:
.LFB0:
	.cfi_startproc
	cmpl	$4, %edx
	ja	.L9
	movl	%edx, %edx
	leaq	.L4(%rip), %rcx
	movslq	(%rcx,%rdx,4), %rax
	addq	%rcx, %rax
	jmp	*%rax
	.section	.rodata
	.align 4
	.align 4
.L4:
	.long	.L8-.L4
	.long	.L7-.L4
	.long	.L6-.L4
	.long	.L5-.L4
	.long	.L3-.L4
	.text
.L3:
	movl	$27, %eax
	ret
.L8:
	movq	(%rsi), %rax
	movq	(%rdi), %rdx
	movq	%rdx, (%rsi)
	ret
.L7:
	movq	(%rsi), %rax
	addq	(%rdi), %rax
	movq	%rax, (%rdi)
	ret
.L6:
	movq	$59, (%rdi)
	movq	(%rsi), %rax
	ret
.L5:
	movq	(%rsi), %rax
	movq	%rax, (%rdi)
	movl	$27, %eax
	ret
.L9:
	movl	$12, %eax
	ret
	.cfi_endproc
.LFE0:
	.size	switch1, .-switch1
	.ident	"GCC: (GNU) 13.2.1 20230801"
	.section	.note.GNU-stack,"",@progbits

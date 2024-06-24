	.file	"vswitch.c"
	.text
	.globl	switchv
	.type	switchv, @function
switchv:
.LFB11:
	.cfi_startproc
	cmpq	$3, %rdi
	je	.L4
	jg	.L3
	testq	%rdi, %rdi
	je	.L5
	cmpq	$2, %rdi
	jne	.L6
	movl	$3003, %eax
	ret
.L3:
	cmpq	$5, %rdi
	jne	.L7
	movl	$3003, %eax
	ret
.L4:
	movl	$3276, %eax
	ret
.L5:
	movl	$2730, %eax
	ret
.L6:
	movl	$3549, %eax
	ret
.L7:
	movl	$3549, %eax
	ret
	.cfi_endproc
.LFE11:
	.size	switchv, .-switchv
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"%ld%ld%ld%ld"
	.text
	.globl	main
	.type	main, @function
main:
.LFB12:
	.cfi_startproc
	pushq	%r12
	.cfi_def_cfa_offset 16
	.cfi_offset 12, -16
	pushq	%rbp
	.cfi_def_cfa_offset 24
	.cfi_offset 6, -24
	pushq	%rbx
	.cfi_def_cfa_offset 32
	.cfi_offset 3, -32
	movl	$2, %edi
	call	switchv
	movq	%rax, %rbx
	movl	$6, %edi
	call	switchv
	movq	%rax, %rbp
	movl	$7, %edi
	call	switchv
	movq	%rax, %r12
	movl	$5, %edi
	call	switchv
	movq	%rax, %r8
	movq	%r12, %rcx
	movq	%rbp, %rdx
	movq	%rbx, %rsi
	leaq	.LC0(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
	popq	%rbx
	.cfi_def_cfa_offset 24
	popq	%rbp
	.cfi_def_cfa_offset 16
	popq	%r12
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE12:
	.size	main, .-main
	.ident	"GCC: (GNU) 13.2.1 20230801"
	.section	.note.GNU-stack,"",@progbits

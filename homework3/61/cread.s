	.file	"cread.c"
	.text
	.p2align 4
	.globl	cread
	.type	cread, @function
cread:
.LFB0:
	.cfi_startproc
	xorl	%eax, %eax
	testq	%rdi, %rdi
	je	.L1
	movq	(%rdi), %rax
.L1:
	ret
	.cfi_endproc
.LFE0:
	.size	cread, .-cread
	.p2align 4
	.globl	cread_alt
	.type	cread_alt, @function
cread_alt:
.LFB3:
	.cfi_startproc
	xorl	%eax, %eax
	testq	%rdi, %rdi
	je	.L6
	movq	(%rdi), %rax
.L6:
	ret
	.cfi_endproc
.LFE3:
	.size	cread_alt, .-cread_alt
	.ident	"GCC: (GNU) 13.2.1 20230801"
	.section	.note.GNU-stack,"",@progbits

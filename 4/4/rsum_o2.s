	.file	"rsum.c"
	.text
	.p2align 4
	.globl	rsum
	.type	rsum, @function
rsum:
.LFB0:
	.cfi_startproc
	endbr64
	xorl	%eax, %eax
	xorl	%r8d, %r8d
	testq	%rsi, %rsi
	jle	.L1
	.p2align 4,,10
	.p2align 3
.L4:
	addq	(%rdi,%rax,8), %r8
	addq	$1, %rax
	cmpq	%rsi, %rax
	jne	.L4
.L1:
	movq	%r8, %rax
	ret
	.cfi_endproc
.LFE0:
	.size	rsum, .-rsum
	.ident	"GCC: (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:

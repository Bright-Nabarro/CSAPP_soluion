	.file	"goto.c"
	.text
	.globl	sum_even
	.type	sum_even, @function
sum_even:
.LFB0:
	.cfi_startproc
	endbr64
	movl	$0, %eax
	movl	$0, %edx
	jmp	.L2
.L6:
	addq	%rax, %rdx
.L3:
	addq	$1, %rax
.L2:
	cmpq	$9, %rax
	jg	.L1
	testb	$1, %al
	je	.L6
	jmp	.L3
.L1:
	movq	%rdx, %rax
	ret
	.cfi_endproc
.LFE0:
	.size	sum_even, .-sum_even
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

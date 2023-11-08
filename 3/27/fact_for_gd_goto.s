	.file	"fact_for_gd_goto.c"
	.text
	.globl	fact_gd_goto
	.type	fact_gd_goto, @function
fact_gd_goto:
.LFB0:
	.cfi_startproc
	endbr64
	cmpl	$1, %edi
	jle	.L4
	movl	$1, %edx
	movl	$2, %eax
.L3:
	imull	%eax, %edx
	addl	$1, %eax
	cmpl	%eax, %edi
	jge	.L3
.L1:
	movl	%edx, %eax
	ret
.L4:
	movl	$1, %edx
.L2:
	jmp	.L1
	.cfi_endproc
.LFE0:
	.size	fact_gd_goto, .-fact_gd_goto
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

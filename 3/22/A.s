	.file	"A.c"
	.text
	.globl	fac
	.type	fac, @function
fac:
.LFB0:
	.cfi_startproc
	endbr64
	movl	$1, %eax
.L2:
	imull	%edi, %eax
	subl	$1, %edi
	cmpl	$1, %edi
	jg	.L2
	ret
	.cfi_endproc
.LFE0:
	.size	fac, .-fac
	.globl	fac_goto
	.type	fac_goto, @function
fac_goto:
.LFB1:
	.cfi_startproc
	endbr64
	movl	$1, %eax
.L4:
	imull	%edi, %eax
	subl	$1, %edi
	cmpl	$1, %edi
	jg	.L4
	ret
	.cfi_endproc
.LFE1:
	.size	fac_goto, .-fac_goto
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

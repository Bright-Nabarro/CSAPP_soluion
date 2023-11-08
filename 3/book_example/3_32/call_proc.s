	.file	"call_proc.c"
	.text
	.globl	call_proc
	.type	call_proc, @function
call_proc:
.LFB0:
	.cfi_startproc
	endbr64
	subq	$24, %rsp
	.cfi_def_cfa_offset 32
	movq	$1, 8(%rsp)
	movl	$2, 4(%rsp)
	movw	$3, 2(%rsp)
	movb	$4, 1(%rsp)
	leaq	4(%rsp), %rcx
	leaq	8(%rsp), %rsi
	leaq	1(%rsp), %rax
	pushq	%rax
	.cfi_def_cfa_offset 40
	pushq	$4
	.cfi_def_cfa_offset 48
	leaq	18(%rsp), %r9
	movl	$3, %r8d
	movl	$2, %edx
	movl	$1, %edi
	call	proc@PLT
	movslq	20(%rsp), %rax
	addq	24(%rsp), %rax
	movswl	18(%rsp), %edx
	movsbl	17(%rsp), %ecx
	subl	%ecx, %edx
	movslq	%edx, %rdx
	imulq	%rdx, %rax
	addq	$40, %rsp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE0:
	.size	call_proc, .-call_proc
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

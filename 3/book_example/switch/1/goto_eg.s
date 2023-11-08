	.file	"goto_eg.c"
	.text
	.globl	fun
	.type	fun, @function
fun:
.LFB0:
	.cfi_startproc
	endbr64
	subq	$100, %rsi
	cmpq	$6, %rsi
	jbe	.L6
	leaq	jt.0(%rip), %rax
	jmp	*(%rax,%rsi,8)
.L2:
	endbr64
	jmp	.L6
.L3:
	endbr64
	jmp	.L6
.L4:
	endbr64
.L6:
	endbr64
	movq	$0, (%rdx)
	ret
.L5:
	endbr64
	jmp	.L6
	.cfi_endproc
.LFE0:
	.size	fun, .-fun
	.section	.data.rel.ro.local,"aw"
	.align 32
	.type	jt.0, @object
	.size	jt.0, 56
jt.0:
	.quad	.L2
	.quad	.L6
	.quad	.L3
	.quad	.L4
	.quad	.L5
	.quad	.L6
	.quad	.L5
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

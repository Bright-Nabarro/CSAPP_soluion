	.file	"comp.c"
	.text
	.globl	comp
	.type	comp, @function
comp:
.LFB0:
	.cfi_startproc
	cmpq	%rsi, %rdi
	sete	%al
	ret
	.cfi_endproc
.LFE0:
	.size	comp, .-comp
	.ident	"GCC: (GNU) 13.2.1 20230801"
	.section	.note.GNU-stack,"",@progbits

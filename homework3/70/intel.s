	.file	"proc.c"
	.intel_syntax noprefix
	.text
	.globl	proc
	.type	proc, @function
proc:
.LFB0:
	.cfi_startproc
	mov	rdx, QWORD PTR 8[rdi]
	mov	rax, QWORD PTR [rdx]
	mov	rax, QWORD PTR [rax]
	sub	rax, QWORD PTR 8[rdx]
	mov	QWORD PTR [rdi], rax
	ret
	.cfi_endproc
.LFE0:
	.size	proc, .-proc
	.ident	"GCC: (GNU) 13.2.1 20230801"
	.section	.note.GNU-stack,"",@progbits

	.file	"umult_full.c"
	.text
	.globl	umult_full
	.type	umult_full, @function
umult_full:
.LFB0:
	.cfi_startproc
	movq	%rdx, %rcx
#APP
# 4 "umult_full.c" 1
	movq	%rdi, %rax		
	mulq	%rsi			
	movq	%rax, 8(%rcx)	
	movq	%rdx, (%rcx)
	
# 0 "" 2
#NO_APP
	ret
	.cfi_endproc
.LFE0:
	.size	umult_full, .-umult_full
	.ident	"GCC: (GNU) 13.2.1 20230801"
	.section	.note.GNU-stack,"",@progbits

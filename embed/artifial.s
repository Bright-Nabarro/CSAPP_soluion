	.file	"mult_ok.c"
	.text
	.globl	tmult_ok_asm
	.type	tmult_ok_asm, @function
tmult_ok_asm:
.LFB0:
	.cfi_startproc
	imulq	%rsi, %rdi
	movq	%rdi, (%rdx)
#APP
# 5 "mult_ok.c" 1
	setae %al
# 0 "" 2
#NO_APP
	movl	$0, %eax
	ret
	.cfi_endproc
.LFE0:
	.size	tmult_ok_asm, .-tmult_ok_asm
	.globl	umult_ok_asm
	.type	umult_ok_asm, @function
umult_ok_asm:
# int umult_ok_asm(unsigned long x, unsigned long y, unsigned long* dest)
# x in %rdi, y in %rsi, dest in %rdx
.LFB1:
	.cfi_startproc
#	imulq	%rsi, %rdi
#	movq	%rdi, (%rdx)
#	testq	%rdi, %rdi
#	setne	%al
	movq	%rdx, $rcx
	movq	%rsi, %rax
	mulq	%rdi			# %rdi * %rax -> %rdx : %rax 
	movq	%rax, (%rcx)
	setae	%al
	movzbl	%al, %eax
	ret
	.cfi_endproc
.LFE1:
	.size	umult_ok_asm, .-umult_ok_asm
	.ident	"GCC: (GNU) 13.2.1 20230801"
	.section	.note.GNU-stack,"",@progbits

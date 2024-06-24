	.file	"mult_ok.c"
	.text
	.globl	tmult_ok_asm
	.type	tmult_ok_asm, @function
tmult_ok_asm:
.LFB0:
	.cfi_startproc
	imulq	%rsi, %rdi
	movq	%rdi, (%rdx)
	testq	%rdi, %rdi
	setg	%al
	movzbl	%al, %eax
	ret
	.cfi_endproc
.LFE0:
	.size	tmult_ok_asm, .-tmult_ok_asm
	.globl	umult_ok_asm
	.type	umult_ok_asm, @function
umult_ok_asm:
.LFB1:
	.cfi_startproc
	movq	%rdx, %rcx
#APP
# 11 "mult_ok.c" 1
	movq	%rdi, %rax	
	mulq	%rsi		
	movq	%rax, (%rcx)	
	setae	%dil
# 0 "" 2
#NO_APP
	movzbl	%dil, %eax
	ret
	.cfi_endproc
.LFE1:
	.size	umult_ok_asm, .-umult_ok_asm
	.globl	main
	.type	main, @function
main:
.LFB2:
	.cfi_startproc
	movl	$0, %eax
	ret
	.cfi_endproc
.LFE2:
	.size	main, .-main
	.ident	"GCC: (GNU) 13.2.1 20230801"
	.section	.note.GNU-stack,"",@progbits

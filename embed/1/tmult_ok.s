	.file	"tmult_ok.c"
	.text
	.globl	tmult_ok_asm
	.type	tmult_ok_asm, @function
tmult_ok_asm:
.LFB11:
	.cfi_startproc
#APP
# 6 "tmult_ok.c" 1
	imulq	%rdi, %rsi
	movq	%rsi, (%rdx)
	seto	%dil
# 0 "" 2
#NO_APP
	movzbl	%dil, %eax
	ret
	.cfi_endproc
.LFE11:
	.size	tmult_ok_asm, .-tmult_ok_asm
	.globl	tmult_ok_asm2
	.type	tmult_ok_asm2, @function
tmult_ok_asm2:
.LFB12:
	.cfi_startproc
	movq	%rdx, %rcx
#APP
# 19 "tmult_ok.c" 1
	movq	%rdi, %rax
	imulq	%rsi
	movq	%rax, (%rcx)
	seto	%dil
# 0 "" 2
#NO_APP
	movzbl	%dil, %eax
	ret
	.cfi_endproc
.LFE12:
	.size	tmult_ok_asm2, .-tmult_ok_asm2
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"overflow"
.LC1:
	.string	"%ld\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB13:
	.cfi_startproc
	subq	$24, %rsp
	.cfi_def_cfa_offset 32
	movq	%fs:40, %rax
	movq	%rax, 8(%rsp)
	xorl	%eax, %eax
	movq	%rsp, %rdx
	movabsq	$-1030792151041, %rdi
	movq	%rdi, %rsi
	call	tmult_ok_asm2
	testl	%eax, %eax
	jne	.L7
.L4:
	movq	(%rsp), %rsi
	leaq	.LC1(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	8(%rsp), %rax
	subq	%fs:40, %rax
	jne	.L8
	movl	$0, %eax
	addq	$24, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	ret
.L7:
	.cfi_restore_state
	leaq	.LC0(%rip), %rdi
	call	puts@PLT
	jmp	.L4
.L8:
	call	__stack_chk_fail@PLT
	.cfi_endproc
.LFE13:
	.size	main, .-main
	.ident	"GCC: (GNU) 13.2.1 20230801"
	.section	.note.GNU-stack,"",@progbits

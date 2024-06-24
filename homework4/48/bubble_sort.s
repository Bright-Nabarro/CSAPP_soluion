	.pos 0
	irmovq stack, %rsp
	call main
	halt

	.align	8
g_data:
	.quad	4
	.quad	3
	.quad	2
	.quad	1
g_end:

bubble_sort:
#	iaddq	$-8, %rsi
	irmovq	$8, %r9
	subq	%r9, %rsi
	jmp	L2
L3:
#	iaddq	$8, %rax
	irmovq	$8, %r9
	addq	%r9, %rax
L5:
#	cmpq	%rsi, %rax
	rrmovq	%rax, %r8
	subq	%rsi, %r8
	je	L7
	mrmovq	8(%rax), %rdx
	mrmovq	(%rax), %rcx
#	cmpq	%rcx, %rdx
	rrmovq	%rdx, %r9
	subq	%rcx, %r9
	jge	L3
	rmmovq	%rcx, 8(%rax)
	rmmovq	%rdx, (%rax)
	jmp	L3
L7:
#	iaddq	$-8, %rsi
	irmovq	$8, %r9
	subq	%r9, %rsi
L2:
#	cmpq	%rdi, %rsi
	rrmovq	%rsi, %r8
	subq	%rdi, %r8
	je	L8
	rrmovq	%rdi, %rax
	jmp	L5
L8:
	ret

main:
	irmovq	g_data, %rdi
	irmovq	g_end, %rsi
	call	bubble_sort
	ret
	
.pos 0x200
stack:

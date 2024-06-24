switchv:
#	cmpq	$3, %rdi
	irmovq	$3, %r8
	subq	%rdi, %r8
	je	L4
	jg	L3
#	testq	%rdi, %rdi
	rrmovq	%rdi, %r8
	andq	%r8, %r8
	je	L5
#	cmpq	$2, %rdi
	irmovq	$2, %r8
	subq	%rdi, %r8
	jne	L6
	irmovq	$3003, %rax
	ret
L3:
#	cmpq	$5, %rdi
	irmovq	$5, %r8
	subq	%rdi, %r8
	jne	L7
	irmovq	$3003, %rax
	ret
L4:
	irmovq	$3276, %rax
	ret
L5:
	irmovq	$2730, %rax
	ret
L6:
	irmovq	$3549, %rax
	ret
L7:
	irmovq	$3549, %rax
	ret

main:
	subq	$80, %rsp
	movq	%rax, 72(%rsp)
	xorq	%rax, %rax
	movq	$0, %rbx
	jmp	L9
L10:
#	leaq	-1(%rbx), %rdi
	irmovq	$1, %r8
	subq	%r8, %rbx
	rrmovq	%rbx, %rdi
	call	switchv
	movq	%rax, (%rsp,%rbx,8)
	addq	$1, %rbx
L9:
#	cmpq	$7, %rbx
	jle	L10
	movq	72(%rsp), %rax
	addq	$80, %rsp
	ret

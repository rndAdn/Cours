	.file	"Test_Memoire.c"
	.section	.rodata
.LC0:
	.string	"Pour i = %d c'est Vrai\n"
.LC1:
	.string	"Pour i = %d c'est Faux\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	$-50, -4(%rbp)
	jmp	.L2
.L5:
	cmpl	$0, -4(%rbp)
	je	.L3
	movl	-4(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
	jmp	.L4
.L3:
	movl	-4(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC1, %edi
	movl	$0, %eax
	call	printf
.L4:
	addl	$1, -4(%rbp)
.L2:
	cmpl	$49, -4(%rbp)
	jle	.L5
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (GNU) 4.7.2"
	.section	.note.GNU-stack,"",@progbits

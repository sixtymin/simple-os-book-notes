	.file	"lab01.c"
	.globl	count
	.data
	.align 4
	.type	count, @object
	.size	count, 4
count:
	.long	1
	.globl	value
	.align 4
	.type	value, @object
	.size	value, 4
value:
	.long	1
	.comm	buf,0,4
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
	movl	count(%rip), %edx
	movl	value(%rip), %eax
	movl	buf(%rip), %esi
	movl	%edx, %ecx
	movl	%esi, %edi
#APP
# 8 "lab01.c" 1
	cld 
	rep 
	stosl
# 0 "" 2
#NO_APP
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 4.8.4-2ubuntu1~14.04.3) 4.8.4"
	.section	.note.GNU-stack,"",@progbits

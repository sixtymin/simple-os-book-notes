	.file	"lab13.c"
	.text
	.globl	ex1
	.type	ex1, @function
ex1:
.LFB0:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
#APP
# 4 "lab13.c" 1
	movl $0xffff, %eax

# 0 "" 2
#NO_APP
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	ex1, .-ex1
	.globl	ex2
	.type	ex2, @function
ex2:
.LFB1:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$16, %esp
#APP
# 10 "lab13.c" 1
	movl %cr0, %eax 

# 0 "" 2
#NO_APP
	movl	%eax, -4(%ebp)
	orl	$-2147483648, -4(%ebp)
	movl	-4(%ebp), %eax
#APP
# 12 "lab13.c" 1
	movl %eax, %cr0

# 0 "" 2
#NO_APP
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE1:
	.size	ex2, .-ex2
	.globl	ex3
	.type	ex3, @function
ex3:
.LFB2:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%esi
	pushl	%ebx
	subl	$32, %esp
	.cfi_offset 6, -12
	.cfi_offset 3, -16
	movl	$2, -28(%ebp)
	movl	$22, -24(%ebp)
	movl	$222, -20(%ebp)
	movl	$2222, -16(%ebp)
	movl	$11, %eax
	movl	-28(%ebp), %ebx
	movl	-24(%ebp), %ecx
	movl	-20(%ebp), %edx
	movl	-16(%ebp), %esi
#APP
# 18 "lab13.c" 1
	int $0x80
# 0 "" 2
#NO_APP
	movl	%eax, -12(%ebp)
	addl	$32, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%esi
	.cfi_restore 6
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE2:
	.size	ex3, .-ex3
	.ident	"GCC: (Ubuntu 4.8.4-2ubuntu1~14.04.3) 4.8.4"
	.section	.note.GNU-stack,"",@progbits

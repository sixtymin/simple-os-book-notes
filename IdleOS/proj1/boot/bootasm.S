
#include <asm.h>

.set PROT_MODE_CSEG,  0x8	# Code Segment selector
.set PROT_MODE_DSEG,  0x10	# Data Segment selector
.set CR0_PE_ON,		  0x1	# protected mode enable flag

.text
.code16

.global start

start:
	cli
	cld

	# Set up segment registers(DS, ES, SS)
	xorw	%ax, %ax
	movw	%ax, %ds
	movw	%ax, %ss
	movw	%ax, %es

seta20.1:
	inb $0x64, %al
	testb $0x2, %al
	jnz seta20.1

	movb $0xd1, %al
	outb %al, $0x64

seta20.2:
	inb $0x64, %al
	testb %al, $0x02
	jnz seta20.2

	movb $0xdf, %al
	outb %al, 0x60

	# switch to protect mode
	lgdt gdtdesc
	movl %cr0, %eax
	orl %eax, $CR0_PE_ON
	movl %eax, %cr0

	# Jump to next insturction, but in 32bit code segment
	# Switches processor into 32bit mode
	ljmp $PROT_MODE_CSEG, $protcseg

.code32
protcseg:
	# Set up Protect mode segment registers
	movw $PROT_MODE_DSEG, %ax
	movw %ax, %es
	movw %ax, %ds
	movw %ax, %ss
	movw %ax, %gs
	movw %ax, %fs

	# setup stack pointer, call into C 
	movw $0x0, %ebp
	movw $start, %esp
	call bootmain

	# if bootmain return(Error),loop.
spin:
	jmp spin

.data
# Bootstrap GDT
.p2align 2
gdt:
	SEG_NULL			# NULL  ITERM
	SEG_ASM(SEGTYPE_EXECUTE | SEGTYPE_READABLE, 0x0, 0xFFFFFFFF)) # Code seg
	SEG_ASM(SEGTYPE_WRITABLE, 0x0, 0xFFFFFFF)					  # Data Seg

gdtdesc:
	.word 0x17
	.long gdt
	

.text
.code16

.global start

start:
	cli
	cld

	xorw	%ax, %ax
	movw	%ax, %ss
	movw	%ax, %es
	movw	%ax, %ds

	movw	$0x7c00, %sp
	call	dispcga

loop:
	jmp	loop

dispcga:
	movw	$0xb800, %ax
	movw	%ax, %es
	xorw	%di, %di	
	movw	$0x06, %cx
	movw	$dispstr, %si
	rep	movsw

	ret

dispstr:
	.byte 'H', 0x30, 'e', 0x30,  'l', 0x30, 'l', 0x30, 'o', 0x30, '.', 0x30

.org 0x1fe, 0x90

.word 0xaa55

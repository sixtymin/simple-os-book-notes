
#.include "defines.h"
.data
hello:
	.string "hello world\n"

.global main

main:
	movl $4, %eax
	movl $1, %ebx
	movl $hello, %ecx
	movl $12, %edx
	int $0x80

	ret

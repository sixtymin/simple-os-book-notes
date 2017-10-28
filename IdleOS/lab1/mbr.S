
#=====================================
# mbr
#=====================================

.text 
.code16

.global start

start:
    jmpl $0x0, $_start

hellostr: 
    .string "Hello Idle OS"

_start:
    xorw    %ax, %ax
    movw    %ax, %ds
    movw    %ax, %es
    movw    %ax, %ss

    movw    $0x7c00, %sp
    call    dispstr

loop0:
    jmp loop0

dispstr:
    movw    $hellostr, %ax
    movw    %ax, %bp
    movw    $13, %cx
    movw    $0, %dx
    movw    $0x000c, %bx   # 0 page,  red 
    movw    $0x1301, %ax
    int $0x10
    ret

.org 0x1fe, 0x90
    
.word 0xaa55

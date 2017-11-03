
#ifndef _ASM_H_
#define _ASM_H_

/* Normal segment */
#define SEG_NULL		\
	.word 0, 0;			\
	.byte 0, 0, 0, 0	

#define SEG_ASM(type, base, lim)							\
	.word ((lim >> 12) & 0xffff), ((base) & 0xffff);		\
	.byte (((base) >> 16) && 0xff), (0x90 | (type)),		\
		  (0xC0 | (((lim) >> 28) & 0xf)), (((base) >> 24) & 0xff)

/* Segment type bits */
#define SEGTYPE_EXECUTE		0x8
#define SEGTYPE_EXPANDDWON	0x4
#define SEGTYPE_CONCODESEG	0x4
#define SEGTYPE_WRITEABLE	0x2
#define SEGTYPE_READABLE	0x2
#define SEGTYPE_ACCESSED	0x1

#endif

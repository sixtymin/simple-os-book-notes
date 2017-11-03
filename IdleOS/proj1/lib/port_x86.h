
#ifndef _PORT_X86_H_
#define _PORT_X86_H_

#include <types.h>

static inline uint8_t inb(uint16_t port) __attribute__((always_inline));
static inline void outb(uint16_t port) __attribute__((always_inline));

static inline uint8_t
inb(uint16_t port) {
	uint_8 data;
	asm volatile ("inb %1, %0" : "=a"(data) :"d"(port) : "memory");
	return data;	
}

static inline void
outb(uint16_t port, uint8_t data) {
	asm volatile ("outb %0, %1" : :"a"(data), "d"(port) :"memory");
}

#endif


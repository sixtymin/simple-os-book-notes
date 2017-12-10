
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "a.h"

extern void print2();
extern void print3();

int main()
{
	print2();
	print3();
	printf("Hello world!\n");
	return 0;
}

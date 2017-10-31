
int count = 1;
int value = 1;
int buf[0];

void main()
{
	asm(
		"cld \n\t"
		"rep \n\t"
		"stosl"
		:
		:"c"(count), "a"(value), "D"(buf[0])
		:
	);
}


#include "part.h"

extern int g_int1, g_int2;
extern char *g_str1, *g_str2;

int main(void){
	int i = 0;
	char *str = "abc";
	
	func_1(i);
	func_2(str);

	g_int1 = 9;
	g_int2 = "defg";

	printf("Global integer is %d and %d, global string is %s and %s.\n", g_int1,
		g_int2, g_str1, g_str2);

	return i;
}
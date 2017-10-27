
#include <stdio.h>

int main(void)
{
    int a, b;
    a = 10;
    printf("a = %d b = %d\n", a, b);
    asm (
        "movl %1, %%eax;\t\n"
        "movl %%eax, %0;\t\n"
        :"=r"(b)
        :"r"(a)
        :"%eax");
    printf("a = %d b = %d\n", a, b);
    return 0;
}

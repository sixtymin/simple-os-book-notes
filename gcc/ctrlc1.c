
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

#define SIG_DEL 0

void ouch(int sig)
{
	printf("OUCH!~ I got signal %d\n", sig);
	(void) signal(SIGINT, SIG_DEL);
}

int main(void)
{
	(void) signal(SIGINT, ouch);
	while(1) {
		printf("Hello World!\n");
		sleep(1);
	}
}

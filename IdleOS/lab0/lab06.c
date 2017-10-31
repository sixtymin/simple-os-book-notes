
#include <stdio.h>
#include <unistd.h>

int main(void)
{
	int child_status, exec_status;

	int pid = fork();
	if(pid == 0)
	{
		printf("child: EXEC lec7_1\n");
		exec_status = execve("lec7_1", NULL, NULL);
		printf("Child: Why would I excecte?\n");

	}
	else
	{
		printf("Parent: Whose your daddy ? \n");
		child_status = wait(pid);
		printf("Parent: the child %d exit with %d\n", pid, child_status);
	}

	return 0;
}

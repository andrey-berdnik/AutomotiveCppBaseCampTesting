#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int globvar = 6;

char buf[] = "a write to stdout\n";

void err_sys(const char *x)
{
	perror(x);
	exit(1);
}

int main(void)
{
	int var = 88;
	pid_t pid;

	if (write(STDOUT_FILENO, buf, sizeof(buf) - 1) != sizeof(buf) - 1)
		err_sys("write error");
	printf("before fork\n");
	if ((pid = fork()) < 0)
	{
		err_sys("fork error");
	}
	else if (pid == 0)
	{ /* child */
		globvar++;
		var++;
	}
	else
	{
		/* parent */
		sleep(2);
	}
	printf("pid = %ld, glob = %d, var = %d\n", (long)getpid(), globvar, var);
	exit(0);
}
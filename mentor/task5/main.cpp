#include <iostream>
#include <csignal>
#include <unistd.h>
#include <unistd.h>


using namespace std;

void signalHandler(int signum)
{
	std::cout << "SIGHUP signal received received.\n";
	exit(signum);
}

int main(void)
{
	signal(SIGHUP, signalHandler);

	pid_t pid;

	printf("before fork\n");

	if ((pid = fork()) < 0)
	{
		cout <<  "fork error";
	}
	else if (pid == 0)
	{ /* child */
		while (true)
		{
			cout << "\n------------------------------------------------"
			<< "\nchild:"
			<< "\nprocess ID of calling process\t=\t" << (long)getpid()
			<< "\nparent process ID of calling process\t=\t" << (long)getppid()
			<< "\nreal user ID of calling process\t=\t" << (long)getuid()
			<< "\neffective user ID of calling process\t=\t" << (long)geteuid()
			<< "\nreal group ID of calling process\t=\t" << (long)getgid()
			<< "\neffective group ID of calling process\t=\t" << (long)getegid()
			<< "\nprocess ID of calling process\t=\t" << (long)getpid()
			<< "\n------------------------------------------------"
			<< endl;
			sleep(2);
		}
	}
	else
	{ /* parent */
		while (true)
		{
			cout << "\n------------------------------------------------"
			<< "\nparent:"
			<< "\nprocess ID of calling process\t=\t" << (long)getpid()
			<< "\nparent process ID of calling process\t=\t" << (long)getppid()
			<< "\nreal user ID of calling process\t=\t" << (long)getuid()
			<< "\neffective user ID of calling process\t=\t" << (long)geteuid()
			<< "\nreal group ID of calling process\t=\t" << (long)getgid()
			<< "\neffective group ID of calling process\t=\t" << (long)getegid()
			<< "\nprocess ID of calling process\t=\t" << (long)getpid()
			<< "\n------------------------------------------------"
			<< endl;
			sleep(2);
		}
	}

	exit(0);
}

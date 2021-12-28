#include <iostream>
#include <csignal>
#include <unistd.h>

using namespace std;

void signalHandler(int signum)
{
	cout << "SIGHUP signal received received.\n";
	exit(signum);
}

int main()
{
	signal(SIGHUP, signalHandler);

	while (1)
	{
		cout << " " << (long)getpid() << " Going to sleep.... " << endl;
		sleep(1);
	}

	return 0;
}
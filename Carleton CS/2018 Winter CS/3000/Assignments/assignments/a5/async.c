#include <string.h>
#include <stdbool.h>
#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>


volatile sig_atomic_t termBool = false;

void sigusr1_handler(int signal_number){

	termBool = true;
}


int main(){

	// Signal handling
	struct sigaction sa1;
	memset(&sa1, 0, sizeof(sa1));
	sa1.sa_handler = &sigusr1_handler;
	int forkValue = fork();

	//CHILD
	if (forkValue == 0){
		if (kill(getppid(), SIGUSR1) < 0){
			printf("ERROR: %s\n", strerror(errno));
		}
	}

	//ERROR HANDLING
	else if (forkValue < 0){
		printf("ERROR: %s\n", strerror(errno));
	}

	//PARENT
	else{
		sigaction(SIGUSR1, &sa1, NULL);
		while (!termBool) pause();

		printf("SIGUSR1 was raised!\n");
	}

	return 0;
}

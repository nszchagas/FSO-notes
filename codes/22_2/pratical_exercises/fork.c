#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>
int main(){
	pid_t pid;

	pid = fork();

	if (pid <0) {
		fprintf(stderr, "Fork failed!");
		return 1;
	} else if (pid == 0) {
		printf("Executing child");
		//execlp("/bin/ls", "ls", NULL);
		execlp("/bin/pwd", "pwd", NULL);
		return 0;
		
	} else {
		int status;
		waitpid(pid,&status,0);
		printf("Returning to parent process with code %d\nPID: %d\n", status, pid);

	}

	return 0;
}

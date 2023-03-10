#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int value = 5;

int main()
{
	int fd1[2];
	pipe(fd1);	

	pid_t pid;

	pid = fork();

	if (pid == 0) { /* child process */
		printf("Entrei no filho!\n");
		close(fd1[0]);
		value += 15;
		write(fd1[1], &value, sizeof(value));
		close(fd1[1]);
		printf ("CHILD: value = %d\n",value); /* LINE A */
		
		return 0;
	}
	else if (pid > 0) { /* parent process */
		wait(NULL);
		close(fd1[1]);
		read(fd1[0], &value, sizeof(value));
		close(fd1[0]);
		printf ("PARENT: value = %d\n",value); /* LINE A */
		return 0;
	}
}

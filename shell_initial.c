#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	while (1) {
		printf("$ ");
		read = getline(&line, &len, stdin);
		if (read == -1) {
		       printf("\n");
		       break;
		}
		
		line[read - 1] = '\0';

		pid_t pid = fork();
		if (pid == 0) {
			if (execlp(line, line, NULL) == -1) {
				perror("Error executing command");
			}
			exit(EXIT_FAILURE);
		} else if (pid < 0) {

			perror("Error forking");
		} else {
			wait(NULL);
		}
	}
	free(line);
	return 0;
}

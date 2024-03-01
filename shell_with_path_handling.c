#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    char *buffer;
    size_t bufsize = 1024;

    buffer = (char *)malloc(bufsize * sizeof(char));
    if (buffer == NULL) {
        perror("Unable to allocate buffer");
        exit(EXIT_FAILURE);
    }

    while (1) {
        printf(":) ");
        getline(&buffer, &bufsize, stdin);

        buffer[strcspn(buffer, "\n")] = 0;

        pid_t pid = fork();
        if (pid == -1) {
            perror("Fork error");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            if (execve(buffer, NULL, NULL) == -1) {
                perror("Command not found");
                exit(EXIT_FAILURE);
            }
        } else {
            wait(NULL);
        }
    }

    free(buffer);
    return 0;
}


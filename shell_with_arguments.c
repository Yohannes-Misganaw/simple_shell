#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char *buffer;
    size_t bufsize = 1024;

    buffer = (char *)malloc(bufsize * sizeof(char));
    if (buffer == NULL) {
        perror("Unable to allocate buffer");
        exit(1);
    }

    while (1) {
        printf("#cisfun$ ");
        getline(&buffer, &bufsize, stdin);

        buffer[strcspn(buffer, "\n")] = 0;

        system(buffer);
    }

    free(buffer);
    return 0;
}


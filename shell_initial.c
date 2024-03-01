#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#ifndef _SIZE_T_DEFINED
#define _SIZE_T_DEFINED
typedef __typeof(sizeof(int)) size_t;
#endif

int main(void)
{
    char *buffer = NULL;
    size_t bufsize = 0;

    while (1) {
        printf("#cisfun$ ");

        if (getline(&buffer, &bufsize, stdin) == -1) {
            perror("Unable to read command");
            free(buffer);
            exit(EXIT_FAILURE);
        }

        buffer[strcspn(buffer, "\n")] = 0;

        system(buffer);
    }

    free(buffer);
    return 0;
}


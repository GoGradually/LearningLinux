#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <termios.h>
#include <unistd.h>

#define INPUT_MAX 1024

void clearLine(char *buffer, int *position) {
    memset(buffer, 0, MAX_INPUT_SIZE);
    *position = 0;
    printf("\r$ ");  // Optionally, print a new prompt
    fflush(stdout);
}

int main() {
    char input[INPUT_MAX];
    int pos = 0;
    while (1) {
        // Display prompt
        printf("MyShell> ");
        fgets(input, MAX_INPUT_SIZE, stdin);

        // Remove newline character
        input[strlen(input) - 1] = '\0';

        // Tokenize input
        char *token = strtok(input, " ");
        char *args[MAX_INPUT_SIZE];
        int i = 0;

        while (token != NULL) {
            args[i++] = token;
            token = strtok(NULL, " ");
        }

        args[i] = NULL;

        // Handle built-in commands
        if (strcmp(args[0], "exit") == 0) {
            exit(0);
        } else if (strcmp(args[0], "cd") == 0) {
            if (args[1] != NULL) {
                chdir(args[1]);
            } else {
                fprintf(stderr, "cd: missing argument\n");
            }
            continue;
        }

        // Fork and execute command
        pid_t pid = fork();

        if (pid == 0) {
            // Child process
            execvp(args[0], args);
            perror("execvp");
            exit(EXIT_FAILURE);
        } else if (pid < 0) {
            perror("fork");
        } else {
            // Parent process
            waitpid(pid, NULL, 0);
        }
    }
    
}
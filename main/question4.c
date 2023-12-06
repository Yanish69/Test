#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <stdio.h>

int main() {
    char command[256];
    char prompt[12] = "enseash %% ";
    char exitPrompt[15] = "enseash [exit:";
    char signPrompt[15] = "enseash [sign:";

    write(STDOUT_FILENO, prompt, sizeof(prompt) - 1);

    while (1) {

        ssize_t bytesRead = read(STDIN_FILENO, command, sizeof(command) - 1);
        command[bytesRead - 1] = '\0';  // Remove newline character

        // If the commande typed by the user is equal to "exit", we exit the programm
        if (strcmp(command, "exit") == 0) {
            exit(0);
        }

        pid_t pid = fork();
        if (pid == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        }

        if (pid == 0) {
            // Child process
            execlp(command, command, (char *)NULL);
            perror("execlp");
            exit(EXIT_FAILURE);
        } else {
            // Parent process
            int status;
            waitpid(pid, &status, 0);
            if (WIFEXITED(status)) {
                write(STDOUT_FILENO, exitPrompt, sizeof(exitPrompt) - 1);
                dprintf(STDOUT_FILENO, "%d", WEXITSTATUS(status));
                write(STDOUT_FILENO, "] %% ", 5);
            } else if (WIFSIGNALED(status)) {
                write(STDOUT_FILENO, signPrompt, sizeof(signPrompt) - 1);
                dprintf(STDOUT_FILENO, "%d", WTERMSIG(status));
                write(STDOUT_FILENO, "] %% ", 5);
            }
        }
    }

    return 0;
}

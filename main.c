//
/***
 *     ________  ________  ________  ________  ___  ___  _______   ___       ___
 *    |\   __  \|\_____  \|\   __  \|\   ____\|\  \|\  \|\  ___ \ |\  \     |\  \
 *    \ \  \|\  \\|___/  /\ \  \|\  \ \  \___|\ \  \\\  \ \   __/|\ \  \    \ \  \
 *     \ \   __  \   /  / /\ \   __  \ \_____  \ \   __  \ \  \_|/_\ \  \    \ \  \
 *      \ \  \ \  \ /  /_/__\ \  \ \  \|____|\  \ \  \ \  \ \  \_|\ \ \  \____\ \  \____
 *       \ \__\ \__\\________\ \__\ \__\____\_\  \ \__\ \__\ \_______\ \_______\ \_______\
 *        \|__|\|__|\|_______|\|__|\|__|\_________\|__|\|__|\|_______|\|_______|\|_______|
 *                                     \|_________|
 *
 *
 */
// Created by Burhan Hošić
//  - - - Quick Manual For Commands in use - - -

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <ncurses.h>


#define ANSI_COLOR_BRIGHT_BLUE    "\x1b[94m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_RESET "\x1b[0m"
#define MAX_COMMAND_LENGTH 100
#define MAX_ARGUMENTS 10

// Function to read user input
char *read_input() {
    char *input = malloc(MAX_COMMAND_LENGTH * sizeof(char));
    if (input == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    printf(ANSI_COLOR_BLUE);
    printf("prompt$ ");
    printf(ANSI_COLOR_RESET);
    fgets(input, MAX_COMMAND_LENGTH, stdin);
    return input;
}

// Function to parse user input
char **parse_input(char *input) {
    char **tokens = malloc(MAX_ARGUMENTS * sizeof(char *));
    if (tokens == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    char *token = strtok(input, " \t\n");
    int i = 0;
    while (token != NULL) {
        tokens[i] = token;
        token = strtok(NULL, " \t\n");
        i++;
    }
    tokens[i] = NULL;
    return tokens;
}

// Function to execute external commands
void execute_external_command(char **args) {
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Child process
        if (execvp(args[0], args) == -1) {
            perror("execvp");
            exit(EXIT_FAILURE);
        }
    } else {
        // Parent process
        wait(NULL);
    }
}

// Function to execute built-in commands
void execute_builtin_command(char **args) {
    if (strcmp(args[0], "rm") == 0) {
        if (args[1] == NULL) {
            printf("Usage: rm [file]\n");
        } else {
            if (remove(args[1]) != 0) {
                perror("rm");
            }
        }
    } else if (strcmp(args[0], "cat") == 0) {
        // Implement cat command
        if (args[1] == NULL) {
            printf("Usage: cat [file]\n");
        } else {
            FILE *file = fopen(args[1], "r");
            if (file == NULL) {
                perror("cat");
            } else {
                char buffer[256];
                while (fgets(buffer, sizeof(buffer), file)) {
                    printf("%s", buffer);
                }
                fclose(file);
            }
        }
    } else if (strcmp(args[0], "clear") == 0) {
        // Implement clear command
        system("clear");
    } else if (strcmp(args[0], "cowsay") == 0) {
        // Implement cowsay command
        if (args[1] == NULL) {
            printf("Usage: cowsay [message]\n");
        } else {
            printf(ANSI_COLOR_RED);
            printf(" _____\n< %s >\n ----- \n        \\   ^__^\n         \\  (oo)\\_______\n            (__)\\        )\\/\\\n                ||----w |\n                ||     ||\n", args[1]);
            printf(ANSI_COLOR_RESET);
        }
    } else {
        // External command
        execute_external_command(args);
    }
}

int main() {
    char *input;
    char **args;
    printf(ANSI_COLOR_BRIGHT_BLUE);
    printf("      ________   ________   ________   ________   ___  ___   _______    ___        ___               ___   ___        ________     \n"
           "     |\\   __  \\ |\\_____  \\ |\\   __  \\ |\\   ____\\ |\\  \\|\\  \\ |\\  ___ \\  |\\  \\      |\\  \\             |\\  \\ |\\  \\      |\\   __  \\    \n"
           "     \\ \\  \\|\\  \\ \\|___/  /|\\ \\  \\|\\  \\\\ \\  \\___|_\\ \\  \\\\\\  \\\\ \\   __/| \\ \\  \\     \\ \\  \\            \\ \\  \\\\_\\  \\     \\ \\  \\|\\  \\   \n"
           "      \\ \\   __  \\    /  / / \\ \\   __  \\\\ \\_____  \\\\ \\   __  \\\\ \\  \\_|/__\\ \\  \\     \\ \\  \\            \\ \\______  \\     \\ \\  \\\\\\  \\  \n"
           "       \\ \\  \\ \\  \\  /  /_/__ \\ \\  \\ \\  \\\\|____|\\  \\\\ \\  \\ \\  \\\\ \\  \\_|\\ \\\\ \\  \\____ \\ \\  \\____        \\|_____|\\  \\  ___\\ \\  \\\\\\  \\ \n"
           "        \\ \\__\\ \\__\\|\\________\\\\ \\__\\ \\__\\ ____\\_\\  \\\\ \\__\\ \\__\\\\ \\_______\\\\ \\_______\\\\ \\_______\\             \\ \\__\\|\\__\\\\ \\_______\\\n"
           "         \\|__|\\|__| \\|_______| \\|__|\\|__||\\_________\\\\|__|\\|__| \\|_______| \\|_______| \\|_______|              \\|__|\\|__| \\|_______|\n"
           "                                         \\|_________|                                                                              \n"
           " ");
    printf(ANSI_COLOR_RESET);
    printf("\n");

    while (1) {
        input = read_input();
        args = parse_input(input);

        if (args[0] != NULL) {
            if (strcmp(args[0], "exit") == 0) {
                // Exits the shell
                break;
            } else {
                execute_builtin_command(args);
            }
        }

        // Free memory
        free(input);
        free(args);
    }

    return 0;
}

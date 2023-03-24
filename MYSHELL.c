

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>

#define BUFFERSIZE 50

int main() {
    char user_input[BUFFERSIZE]; // array to store user input
    struct tm *timeinfo; // structure to store time info
    char* command[100]; // array to store command
    char* path = "/bin/"; // path to execute the command
    char array[20]; // array to store the path and command
    time_t rawtime; // variable to store raw time
    pid_t pid; // process id

    do {
        time(&rawtime); // get the current time
        timeinfo = localtime(&rawtime); // convert raw time to time info
        printf("%s" ,asctime(timeinfo)); // print the time info

        if (fgets(user_input, BUFFERSIZE, stdin) == NULL) {
            array[strcspn(user_input, "\n")] = 0; // remove the newline character from the user input
        }

        if (strcmp(user_input, "echo") == 0) {
            command[1] = NULL; // set the second element of the command array to NULL
        }
        if (strcmp(user_input, "exit") == 0) {
            exit(0); // exit the program with status 0
        }
        char *token;
        token = strtok(user_input, " \t\n"); // tokenize the user input
        int i = 0;
        while (token != NULL) {
            command[i] = token; // store the token in the command array
            token = strtok(NULL, " \t\n"); // get the next token
            i++;
        }
        command[i] = NULL; // set the last element of the command array to NULL
        strcpy(array, path); // copy the path to the array
        strcpy(array, command[0]); // copy the first element of the command array to the array
        pid = fork(); // create a new process
        if (pid < 0) {
            printf("ERROR: Unable to fork\n"); // print error if the fork failed
            break;
        }
        if (pid = 0) {
            wait(NULL); // wait for the child process to complete
        }
        else {
            execvp(array, command); // execute the command
            printf("ERROR: %s\n", strerror(errno)); // print error if the execution failed
        }
    } while (strcmp(user_input, "exit"));
}



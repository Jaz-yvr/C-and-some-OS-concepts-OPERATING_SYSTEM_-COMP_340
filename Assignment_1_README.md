# MYSHELL.C

The code is a command-line interpreter that prompts the user for input, processes the input as a command, and executes the command. Each time the interpreter prompts the user for input, it also prints the current time. The interpreter continues to prompt the user for input until the user enters "exit".

The code includes the standard input/output library and the string library, as well as the time library and the error number library. It defines a buffer size of 50 characters for user input.

In the main function, the code declares several variables including an array to hold the user input, an array of pointers to hold the command, a string to hold the path to the command, an array to hold the command path, a struct to hold the current time, a variable to hold the raw time, and a variable to hold the process ID.

The code then enters a loop that prompts the user for input, processes the input, and executes the command. It uses the "fgets" function to read the user input, and the "strtok" function to tokenize the input into separate commands. If the user enters "echo", the command array is set to null. If the user enters "exit", the program exits.

The code then uses the "strcpy" function to concatenate the path and command, and the "fork" function to create a new process. If the process ID is less than 0, the code prints an error message. If the process ID is not 0, the parent process waits for the child process to complete. If the process ID is 0, the code uses the "execvp" function to execute the command and the "strerror" function to print an error message if the command fails.
![image](https://user-images.githubusercontent.com/86030152/227495908-d191f99d-dd44-4581-a7bb-3cd361e4d6d1.png)

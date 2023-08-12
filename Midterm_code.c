#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_PROCESSES 100

// Define a structure to store the process details
struct Process {
    int process_id;  // Store the ID of the process
    int arrival_time;  // Store the arrival time of the process
    int burst_time;  // Store the burst time of the process
};

// Function to compare two processes based on their burst time
// This function is used as a comparison function for the qsort function
int compare_burst_time(const void *a, const void *b) {
    struct Process *p1 = (struct Process *) a;
    struct Process *p2 = (struct Process *) b;
    return (p1->burst_time - p2->burst_time);
}

// Function to implement the Shortest Job First (SJF) algorithm with preemption
void sjf_p(struct Process processes[], int n) {
    int current_time = 0;  // Store the current time
    int waiting_time = 0;  // Store the waiting time for a process
    int turnaround_time = 0;  // Store the turnaround time for a process

    // Sorting the processes based on burst time
    qsort(processes, n, sizeof(struct Process), compare_burst_time);

    // Printing the header for the output
    printf("Process ID\tArrival Time\tBurst Time\tTurnaround Time\tWaiting Time\n");

    // Calculating and printing the waiting time, turnaround time and other details of each process
    for (int i = 0; i < n; i++) {
        current_time += processes[i].burst_time;
        turnaround_time = current_time - processes[i].burst_time;
        waiting_time = turnaround_time - processes[i].burst_time;

        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
               processes[i].process_id, processes[i].arrival_time, processes[i].burst_time,
               turnaround_time, waiting_time);
    }
}

// Function to implement the Shortest Job First (SJF) algorithm
void SJF(struct Process *processes, int n) {
    // Sorting the processes based on their burst time
    qsort(processes, n, sizeof(struct Process), compare_burst_time);
    
    int completion_time[n];   // Array to store the completion time of each process
    int waiting_time[n];      // Array to store the waiting time of each process
    int turnaround_time[n];  // Array to store the turnaround time of each process
    
    // Initializing the completion time, waiting time, and turnaround time for the first process
    completion_time[0] = processes[0].burst_time;
    waiting_time[0] = 0;
    turnaround_time[0] = completion_time[0];
    
    // Calculating the completion time, waiting time, and turnaround time for the rest of the processes
    for (int i = 1; i < n; i++) {
        completion_time[i] = completion_time[i - 1] + processes[i].burst_time;
        waiting_time[i] = completion_time[i] - processes[i].burst_time;
        turnaround_time[i] = completion_time[i] - processes[i].burst_time;
    }
    
    // Printing the process details
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", processes[i].process_id, processes[i].burst_time,
               waiting_time[i], turnaround_time[i]);
    }
}

int main() {
    int n;
    printf("SJF only\n");
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    struct Process processes[n];  // Array to store the process details
    
    // Taking the burst time as input for each process
    for (int i = 0; i < n; i++) {
        printf("Enter the burst time of process %d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
        processes[i].process_id = i + 1;
    }
    
    
    
    // Calling the SJF function to implement the algorithm
    SJF(processes, n);

    printf("SJF-P\n");

    // Reading the number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Reading the arrival time and burst time of each process
    for (int i = 0; i < n; i++) {
        processes[i].process_id = i + 1;

        printf("Enter the arrival time for process %d: ", i + 1);
        scanf("%d", &processes[i].arrival_time);

        printf("Enter the burst time for process %d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
    }

    // Calling the shortest job first scheduling algorithm
    sjf_p(processes, n);
    
    return 0;
}

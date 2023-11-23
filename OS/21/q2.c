/*Q.2 Write a C program to simulate Preemptive Priority scheduling. The arrival
time
and first CPU-burst and priority for different n number of
processes should be input to the
algorithm. Assume the fixed IO
waiting time (2 units). The next CPU-burst should be generated randomly. The
output should
give Gantt chart, turnaround time and waiting time for each
process. Also find the average waiting time and turnaround time.*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 10

// Process structure to store process information
struct Process {
    int process_id;
    int arrival_time;
    int cpu_burst;
    int priority;
    int waiting_time;
    int turnaround_time;
};

// Function declarations
void preemptive_priority_scheduling(struct Process processes[], int n);

int main() {
    int n;
    struct Process processes[MAX_PROCESSES];

    // Seed for random number generation
    srand(time(NULL));

    // Input number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Input process details
    printf("Enter arrival time, first CPU-burst, and priority for each process:\n");
    for (int i = 0; i < n; ++i) {
        processes[i].process_id = i + 1;
        printf("Process %d: ", i + 1);
        scanf("%d %d %d", &processes[i].arrival_time, &processes[i].cpu_burst, &processes[i].priority);
        processes[i].waiting_time = 0;
        processes[i].turnaround_time = 0;
    }

    // Run the Preemptive Priority Scheduling algorithm
    preemptive_priority_scheduling(processes, n);

    // Calculate and display average waiting time and turnaround time
    double avg_waiting_time = 0, avg_turnaround_time = 0;
    for (int i = 0; i < n; ++i) {
        avg_waiting_time += processes[i].waiting_time;
        avg_turnaround_time += processes[i].turnaround_time;
    }
    avg_waiting_time /= n;
    avg_turnaround_time /= n;

    printf("\nAverage Waiting Time: %.2lf\n", avg_waiting_time);
    printf("Average Turnaround Time: %.2lf\n", avg_turnaround_time);

    return 0;
}

void preemptive_priority_scheduling(struct Process processes[], int n) {
    int time = 0; // Current time
    int completed = 0; // Number of completed processes
    int current_process = -1; // Index of the currently running process

    printf("\nGantt Chart:\n");
    printf("--------------\n");

    while (completed < n) {
        // Find the process with the highest priority that has arrived
        int highest_priority = -1;
        for (int i = 0; i < n; ++i) {
            if (processes[i].arrival_time <= time && processes[i].turnaround_time == 0 &&
                (highest_priority == -1 || processes[i].priority < processes[highest_priority].priority)) {
                highest_priority = i;
            }
        }

        // If a process is found, execute it
        if (highest_priority != -1) {
            if (current_process != highest_priority) {
                // Process switch
                if (current_process != -1) {
                    printf("| P%d ", processes[current_process].process_id);
                }
                current_process = highest_priority;
            }

            // Generate random next CPU-burst
            int next_burst = rand() % 10 + 1;
            printf("(%d) ", time);
            time += next_burst;

            // Update waiting and turnaround times
            processes[current_process].waiting_time += time - processes[current_process].arrival_time -
                                                       processes[current_process].turnaround_time;
            processes[current_process].turnaround_time += next_burst;

            completed++;
        } else {
            // No process is ready; idle time
            printf("| Idle ");
            time++;
        }
    }

    // Print the final process in the Gantt chart
    if (current_process != -1) {
        printf("| P%d ", processes[current_process].process_id);
    }

    printf("(%d) |\n", time);
}


#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 10


struct Process {
    int process_id;
    int arrival_time;
    int cpu_burst;
    int priority;
    int waiting_time;
    int turnaround_time;
};


void non_preemptive_priority_scheduling(struct Process processes[], int n);

int main() {
    int n;
    struct Process processes[MAX_PROCESSES];

 
    printf("Enter the number of processes: ");
    scanf("%d", &n);

   
    printf("Enter arrival time, burst time, and priority for each process:\n");
    for (int i = 0; i < n; ++i) {
        processes[i].process_id = i + 1;
        printf("Process %d: ", i + 1);
        scanf("%d %d %d", &processes[i].arrival_time, &processes[i].cpu_burst, &processes[i].priority);
        processes[i].waiting_time = 0;
        processes[i].turnaround_time = 0;
    }

   
    non_preemptive_priority_scheduling(processes, n);

    
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

void non_preemptive_priority_scheduling(struct Process processes[], int n) {
    int time = 0; 
    int completed = 0;
    int current_process = -1; 

    printf("\nGantt Chart:\n");
    printf("--------------\n");

    while (completed < n) {
    
        int highest_priority = -1;
        for (int i = 0; i < n; ++i) {
            if (processes[i].arrival_time <= time && processes[i].turnaround_time == 0 &&
                (highest_priority == -1 || processes[i].priority < processes[highest_priority].priority)) {
                highest_priority = i;
            }
        }

    
        if (highest_priority != -1) {
            if (current_process != highest_priority) {
             
                if (current_process != -1) {
                    printf("| P%d ", processes[current_process].process_id);
                }
                current_process = highest_priority;
            }

            printf("(%d) ", time);
            time += processes[current_process].cpu_burst;

           
            processes[current_process].waiting_time = time - processes[current_process].arrival_time -
                                                       processes[current_process].cpu_burst;
            processes[current_process].turnaround_time = processes[current_process].waiting_time +
                                                          processes[current_process].cpu_burst;

            completed++;
        } else {
           
            printf("| Idle ");
            time++;
        }
    }

 
    if (current_process != -1) {
        printf("| P%d ", processes[current_process].process_id);
    }

    printf("(%d) |\n", time);
}


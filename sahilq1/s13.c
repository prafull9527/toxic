//s13 q1
#include <stdio.h>
#define MAX_PROCESSES 10
typedef struct {
int arrival_time;
int burst_time;
int remaining_time;
int turnaround_time;
int waiting_time;
int is_completed;
} Process;
void round_robin(Process processes[], int num_processes, int time_quantum) {
int remaining_processes = num_processes;
int time = 0;
while (remaining_processes > 0) {
for (int i = 0; i < num_processes; i++) {
if (processes[i].is_completed) {
continue;
}
int current_burst = (processes[i].remaining_time < time_quantum) ?
processes[i].remaining_time : time_quantum;
processes[i].remaining_time -= current_burst;
time += current_burst;
printf("| P%d ", i + 1);
if (processes[i].remaining_time == 0) {
    processes[i].turnaround_time = time - processes[i].arrival_time;
    processes[i].waiting_time = processes[i].turnaround_time -
    processes[i].burst_time;
    processes[i].is_completed = 1;
    remaining_processes--;
    }
    }
    }
    }
    int main() {
    int num_processes;
    int time_quantum;
    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);
    if (num_processes <= 0 || num_processes > MAX_PROCESSES) {
    printf("Invalid number of processes. Please enter a number between 1 and %d.\n",
    MAX_PROCESSES);
    return 1;
    }
    printf("Enter the time quantum: ");
    scanf("%d", &time_quantum);
    if (time_quantum <= 0) {
    printf("Invalid time quantum. Please enter a positive number.\n");
    return 1;
    }
    Process processes[MAX_PROCESSES];
    for (int i = 0; i < num_processes; i++) {
    printf("Enter arrival time for process P%d: ", i + 1);
    scanf("%d", &processes[i].arrival_time);
    printf("Enter burst time for process P%d: ", i + 1);
    scanf("%d", &processes[i].burst_time);
    processes[i].remaining_time = processes[i].burst_time;
    processes[i].is_completed = 0;
    }
    printf("\nGantt Chart:\n|");
    round_robin(processes, num_processes, time_quantum);
    printf("|\n\nTurnaround Time and Waiting Time:\n");
    float total_turnaround_time = 0;
    float total_waiting_time = 0;
    for (int i = 0; i < num_processes; i++) {
    printf("Process P%d:\tTurnaround Time: %d\tWaiting Time: %d\n", i + 1,
    processes[i].turnaround_time, processes[i].waiting_time);
    total_turnaround_time += processes[i].turnaround_time;
    total_waiting_time += processes[i].waiting_time;
    }
    float avg_turnaround_time = total_turnaround_time / num_processes;
    float avg_waiting_time = total_waiting_time / num_processes;
    printf("\nAverage Turnaround Time: %.2f\nAverage Waiting Time: %.2f\n",
    avg_turnaround_time, avg_waiting_time);
    return 0;
}
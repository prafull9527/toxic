#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#define MAX_COMMAND_LENGTH 1024
#define MAX_TOKENS 100
void execute_command(char *tokens[]) {
pid_t pid = fork();
if (pid == -1) {
perror("fork");
exit(EXIT_FAILURE);
} else if (pid == 0) {
execvp(tokens[0], tokens);
perror("execvp");
exit(EXIT_FAILURE);
} else {
waitpid(pid, NULL, 0);
}
}
void typeline_command(int n, char *filename) {
FILE *file;
char line[MAX_COMMAND_LENGTH];
file = fopen(filename, "r");
if (file == NULL) {
perror("fopen");
return;
}
for (int i = 0; i < n && fgets(line, sizeof(line), file) != NULL; i++) {
printf("%s", line);
}
fclose(file);
}
int main() {
char command[MAX_COMMAND_LENGTH];
char *tokens[MAX_TOKENS];
char *token;
while (1) {
printf("myshell$ ");
fgets(command, sizeof(command), stdin);
command[strcspn(command, "\n")] = '\0';
int token_count = 0;
token = strtok(command, " ");
while (token != NULL) {
tokens[token_count++] = token;
token = strtok(NULL, " ");
}
if (token_count >= 4 && strcmp(tokens[0], "typeline") == 0 && tokens[1][0] == '+')
{
int n = atoi(tokens[1] + 1);
if (n > 0) {
typeline_command(n, tokens[2]);
} else {
printf("Invalid line count.\n");
}
} else {
tokens[token_count] = NULL; 
execute_command(tokens);
}
}
return 0;
}




//q2
#include <stdio.h>
#include <stdlib.h>
#define MAX_PROCESSES 10
typedef struct {
int process_id;
int arrival_time;
int burst_time;
int turnaround_time;
int waiting_time;
} Process;
void swap(Process *xp, Process *yp) {
Process temp = *xp;
*xp = *yp;
*yp = temp;
}
void sort_by_arrival_time(Process processes[], int num_processes) {
for (int i = 0; i < num_processes - 1; i++) {
for (int j = 0; j < num_processes - i - 1; j++) {
if (processes[j].arrival_time > processes[j + 1].arrival_time) {
swap(&processes[j], &processes[j + 1]);
}
}
}
}
void sort_by_burst_time(Process processes[], int num_processes) {
for (int i = 0; i < num_processes - 1; i++) {
for (int j = 0; j < num_processes - i - 1; j++) {
if (processes[j].burst_time > processes[j + 1].burst_time) {
swap(&processes[j], &processes[j + 1]);
}
}
}
}
void sjf_scheduling(Process processes[], int num_processes) {
int completion_time = 0;
for (int i = 0; i < num_processes; i++) {
if (processes[i].arrival_time > completion_time) {
completion_time = processes[i].arrival_time;
}
processes[i].waiting_time = completion_time - processes[i].arrival_time;
processes[i].turnaround_time = processes[i].waiting_time +
processes[i].burst_time;
completion_time += processes[i].burst_time;
}
}
void print_gantt_chart(Process processes[], int num_processes) {
printf("Gantt Chart:\n");
for (int i = 0; i < num_processes; i++) {
printf("| P%d ", processes[i].process_id);
}
printf("|\n");
}
void print_results(Process processes[], int num_processes) {
printf("\nTurnaround Time and Waiting Time:\n");
float total_turnaround_time = 0;
float total_waiting_time = 0;
for (int i = 0; i < num_processes; i++) {
printf("Process P%d:\tTurnaround Time: %d\tWaiting Time: %d\n",
processes[i].process_id,
processes[i].turnaround_time, processes[i].waiting_time);
total_turnaround_time += processes[i].turnaround_time;
total_waiting_time += processes[i].waiting_time;
}
float avg_turnaround_time = total_turnaround_time / num_processes;
float avg_waiting_time = total_waiting_time / num_processes;
printf("\nAverage Turnaround Time: %.2f\nAverage Waiting Time: %.2f\n",
avg_turnaround_time, avg_waiting_time);
}
int main() {
int num_processes;
printf("Enter the number of processes: ");
scanf("%d", &num_processes);
if (num_processes <= 0 || num_processes > MAX_PROCESSES) {
printf("Invalid number of processes. Please enter a number between 1 and %d.\n",
MAX_PROCESSES);
return 1;
}
Process processes[MAX_PROCESSES];
for (int i = 0; i < num_processes; i++) {
processes[i].process_id = i + 1;
printf("Enter arrival time for process P%d: ", processes[i].process_id);
scanf("%d", &processes[i].arrival_time);
printf("Enter burst time for process P%d: ", processes[i].process_id);
scanf("%d", &processes[i].burst_time);
}
sort_by_arrival_time(processes, num_processes);
sjf_scheduling(processes, num_processes);
print_gantt_chart(processes, num_processes);
print_results(processes, num_processes);
return 0;
}
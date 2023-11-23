#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#define MAX_COMMAND_LENGTH 1024
#define MAX_TOKENS 100
void tokenizeCommand(char *command, char *tokens[]) {
int i = 0;
tokens[i] = strtok(command, " \t\n");
while (tokens[i] != NULL && i < MAX_TOKENS - 1) {
i++;
tokens[i] = strtok(NULL, " \t\n");
}
tokens[i] = NULL;
}
void executeCommand(char *tokens[]) {
pid_t pid = fork();
if (pid == -1) {
perror("fork");
} else if (pid == 0) {
if (execvp(tokens[0], tokens) == -1) {
perror("execvp");
exit(EXIT_FAILURE);
}
} else {
int status;
waitpid(pid, &status, 0);
if (WIFEXITED(status)) {
printf("Child process exited with status %d\n", WEXITSTATUS(status));
} else {
printf("Child process did not exit normally\n");
}
}
}
void typelineCommand(char *filename) {
FILE *file = fopen(filename, "r");
if (file == NULL) {
perror("fopen");
return;
}
char line[MAX_COMMAND_LENGTH];
while (fgets(line, sizeof(line), file) != NULL) {
printf("%s", line);
}
fclose(file);
}
int main() {
char command[MAX_COMMAND_LENGTH];
char *tokens[MAX_TOKENS];
while (1) {
printf("myshell$ ");
fflush(stdout);
if (fgets(command, sizeof(command), stdin) == NULL) {
break;
}
command[strcspn(command, "\n")] = '\0';
tokenizeCommand(command, tokens);
if (tokens[0] != NULL && strcmp(tokens[0], "typeline") == 0) {
if (tokens[1] != NULL) {
typelineCommand(tokens[1]);
} else {
printf("Usage: typeline filename\n");
}
} else if (tokens[0] != NULL) {
executeCommand(tokens);
}
}
return 0;
}






//q2
#include <stdio.h>
void calculateTurnaroundTimeAndWaitingTime(int processes[], int n, int burstTime[], int
waitingTime[], int turnaroundTime[]) {
turnaroundTime[0] = burstTime[0];
waitingTime[0] = 0;
for (int i = 1; i < n; i++) {
turnaroundTime[i] = turnaroundTime[i - 1] + burstTime[i];
waitingTime[i] = turnaroundTime[i - 1];
}
}
void performSJFScheduling(int processes[], int n, int arrivalTime[], int burstTime[]) {
int remainingBurstTime[n];
int turnaroundTime[n];
int waitingTime[n];
for (int i = 0; i < n; i++) {
remainingBurstTime[i] = burstTime[i];
}
int currentTime = 0; 
int executedProcesses = 0; 
while (executedProcesses < n) {
int shortestJob = -1;
int shortestBurstTime = 9999;
for (int i = 0; i < n; i++) {
if (arrivalTime[i] <= currentTime && remainingBurstTime[i] < shortestBurstTime
&& remainingBurstTime[i] > 0) {
shortestJob = i;
shortestBurstTime = remainingBurstTime[i];
}
}
if (shortestJob == -1) {
currentTime++;
} else {
remainingBurstTime[shortestJob]--;
currentTime++;
if (remainingBurstTime[shortestJob] == 0) {
turnaroundTime[shortestJob] = currentTime - arrivalTime[shortestJob];
waitingTime[shortestJob] = turnaroundTime[shortestJob] -
burstTime[shortestJob];
executedProcesses++;
}
}
}
printf("\nGantt Chart:\n");
for (int i = 0; i < n; i++) {
printf("| P%d ", processes[i]);
}
printf("|\n");
printf("\nProcess\tTurnaround Time\tWaiting Time\n");
for (int i = 0; i < n; i++) {
printf("P%d\t%d\t\t%d\n", processes[i], turnaroundTime[i], waitingTime[i]);
}
float averageTurnaroundTime = 0, averageWaitingTime = 0;
for (int i = 0; i < n; i++) {
averageTurnaroundTime += turnaroundTime[i];
averageWaitingTime += waitingTime[i];
}
averageTurnaroundTime /= n;
averageWaitingTime /= n;
printf("\nAverage Turnaround Time: %.2f", averageTurnaroundTime);
printf("\nAverage Waiting Time: %.2f\n", averageWaitingTime);
}
int main() {
int n;
printf("Enter the number of processes: ");
scanf("%d", &n);
int processes[n];
int arrivalTime[n];
int burstTime[n];
printf("Enter the arrival time and burst time for each process:\n");
for (int i = 0; i < n; i++) {
printf("Process %d:\n", i + 1);
processes[i] = i + 1;
printf("Arrival Time: ");
scanf("%d", &arrivalTime[i]);
scanf("%d", &burstTime[i]);
}
performSJFScheduling(processes, n, arrivalTime, burstTime);
return 0;
}
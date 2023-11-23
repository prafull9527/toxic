//s18 q1
#include <stdio.h>
#include <stdlib.h>
int findLRUPageIndex(int *lastUsed, int n) {
int minIndex = 0;
for (int i = 1; i < n; i++) {
if (lastUsed[i] < lastUsed[minIndex]) {
minIndex = i;
}
}
return minIndex;
}
void simulateDemandPagingLRU(int *referenceString, int referenceStringLength, int n) {
int frames[n];
int lastUsed[n];
int pageFaults = 0;
for (int i = 0; i < n; i++) {
frames[i] = -1; 
lastUsed[i] = 0;
}
for (int i = 0; i < referenceStringLength; i++) {
int page = referenceString[i];
int pagePresent = 0;
for (int j = 0; j < n; j++) {
if (frames[j] == page) {
pagePresent = 1;
lastUsed[j] = i + 1; 
break;
}
}
if (!pagePresent) {
int lruIndex = findLRUPageIndex(lastUsed, n);
frames[lruIndex] = page;
lastUsed[lruIndex] = i + 1; 
pageFaults++;
}
printf("%d ", page);
}
printf("\nTotal Page Faults: %d\n", pageFaults);
}
int main() {
int referenceString[] = {3, 4, 5, 6, 3, 4, 7, 3, 4, 5, 6, 7, 2, 4, 6};
int referenceStringLength = sizeof(referenceString) / sizeof(referenceString[0]);
int n = 3;
simulateDemandPagingLRU(referenceString, referenceStringLength, n);
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
void displayGanttChart(int processes[], int n, int burstTime[], int turnaroundTime[]) {
printf("\nGantt Chart:\n");
for (int i = 0; i < n; i++) {
printf("| P%d ", processes[i]);
}
printf("|\n");
printf("0");
for (int i = 0; i < n; i++) {
printf(" %d", turnaroundTime[i]);
}
printf("\n");
}
void displayAverageTimes(int turnaroundTime[], int waitingTime[], int n) {
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
int waitingTime[n];
int turnaroundTime[n];
printf("Enter the arrival time and burst time for each process:\n");
for (int i = 0; i < n; i++) {
printf("Process %d:\n", i + 1);
processes[i] = i + 1;
printf("Arrival Time: ");
scanf("%d", &arrivalTime[i]);
printf("Burst Time: ");
scanf("%d", &burstTime[i]);
}
for (int i = 0; i < n - 1; i++) {
for (int j = 0; j < n - i - 1; j++) {
if (arrivalTime[j] > arrivalTime[j + 1]) {
int tempArrival = arrivalTime[j];
arrivalTime[j] = arrivalTime[j + 1];
arrivalTime[j + 1] = tempArrival;
int tempBurst = burstTime[j];
burstTime[j] = burstTime[j + 1];
burstTime[j + 1] = tempBurst;
int tempProcess = processes[j];
processes[j] = processes[j + 1];
processes[j + 1] = tempProcess;
}
}
}
calculateTurnaroundTimeAndWaitingTime(processes, n, burstTime, waitingTime,
turnaroundTime);
displayGanttChart(processes, n, burstTime, turnaroundTime);
printf("\nProcess\tTurnaround Time\tWaiting Time\n");
for (int i = 0; i < n; i++) {
printf("P%d\t%d\t\t%d\n", processes[i], turnaroundTime[i], waitingTime[i]);
}
displayAverageTimes(turnaroundTime, waitingTime, n);
return 0;
}
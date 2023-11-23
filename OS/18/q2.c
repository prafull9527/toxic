/*Q.2 Write a C program to simulate FCFS CPU-scheduling. The arrival time and
first CPU-burst of different jobs should be input to the system. Accept no. of
Processes, arrival time and burst time. The output should give Gantt chart,
turnaround time and waiting time for each process. Also find the average
waiting time and turnaround time.*/


#include <stdio.h>

// Function to calculate turnaround time and waiting time
void calculateTurnaroundTimeAndWaitingTime(int processes[], int n, int burstTime[], int waitingTime[], int turnaroundTime[]) 
{
    // Turnaround time for the first process is its burst time
    turnaroundTime[0] = burstTime[0];

    // Waiting time for the first process is 0
    waitingTime[0] = 0;

    // Calculate turnaround time and waiting time for each process
    for (int i = 1; i < n; i++)
     {
        turnaroundTime[i] = turnaroundTime[i - 1] + burstTime[i];
        waitingTime[i] = turnaroundTime[i - 1];
    }
}

// Function to display Gantt chart
void displayGanttChart(int processes[], int n, int burstTime[], int turnaroundTime[]) 
{
    printf("\nGantt Chart:\n");

    // Display process numbers
    for (int i = 0; i < n; i++) {
        printf("| P%d ", processes[i]);
    }

    printf("|\n");

    // Display turnaround time
    printf("0");

    for (int i = 0; i < n; i++) {
        printf("      %d", turnaroundTime[i]);
    }

    printf("\n");
}

// Function to calculate and display average turnaround time and waiting time
void displayAverageTimes(int turnaroundTime[], int waitingTime[], int n) 
{
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

    // Sort processes based on arrival time (if not already sorted)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arrivalTime[j] > arrivalTime[j + 1]) {
                // Swap arrival times
                int tempArrival = arrivalTime[j];
                arrivalTime[j] = arrivalTime[j + 1];
                arrivalTime[j + 1] = tempArrival;

                // Swap burst times
                int tempBurst = burstTime[j];
                burstTime[j] = burstTime[j + 1];
                burstTime[j + 1] = tempBurst;

                // Swap process numbers
                int tempProcess = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = tempProcess;
            }
        }
    }

    // Calculate turnaround time and waiting time
    calculateTurnaroundTimeAndWaitingTime(processes, n, burstTime, waitingTime, turnaroundTime);

    // Display Gantt chart
    displayGanttChart(processes, n, burstTime, turnaroundTime);

    // Display turnaround time and waiting time for each process
    printf("\nProcess\tTurnaround Time\tWaiting Time\n");

    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\n", processes[i], turnaroundTime[i], waitingTime[i]);
    }

    // Display average turnaround time and waiting time
    displayAverageTimes(turnaroundTime, waitingTime, n);

    return 0;
}


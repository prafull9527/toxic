/*Q.2 Write the program to simulate Non-preemptive Shortest Job First (SJF) –
scheduling. The arrival time and first CPU-burst of different jobs should be
input to the system. Accept no. of Processes, arrival time and burst time. The
output should give Gantt chart, turnaround time and waiting time for each
process. Also find the average waiting time and turnaround time.*/



#include <stdio.h>

// Function to calculate turnaround time and waiting time
void calculateTurnaroundTimeAndWaitingTime(int processes[], int n, int burstTime[], int waitingTime[], int turnaroundTime[]) {
    turnaroundTime[0] = burstTime[0];
    waitingTime[0] = 0;

    for (int i = 1; i < n; i++) {
        turnaroundTime[i] = turnaroundTime[i - 1] + burstTime[i];
        waitingTime[i] = turnaroundTime[i - 1];
    }
}

// Function to perform SJF scheduling
void performSJFScheduling(int processes[], int n, int arrivalTime[], int burstTime[]) {
    int remainingBurstTime[n];
    int turnaroundTime[n];
    int waitingTime[n];

    // Copy burst times to remaining burst times
    for (int i = 0; i < n; i++) {
        remainingBurstTime[i] = burstTime[i];
    }

    int currentTime = 0; // Current time during simulation
    int executedProcesses = 0; // Number of processes executed

    while (executedProcesses < n) {
        int shortestJob = -1;
        int shortestBurstTime = 9999;

        // Find the shortest job that has arrived
        for (int i = 0; i < n; i++) {
            if (arrivalTime[i] <= currentTime && remainingBurstTime[i] < shortestBurstTime && remainingBurstTime[i] > 0) {
                shortestJob = i;
                shortestBurstTime = remainingBurstTime[i];
            }
        }

        // If no job is found, increment the current time
        if (shortestJob == -1) {
            currentTime++;
        } else {
            // Execute the shortest job
            remainingBurstTime[shortestJob]--;
            currentTime++;

            // If the job is completed, calculate turnaround time and waiting time
            if (remainingBurstTime[shortestJob] == 0) {
                turnaroundTime[shortestJob] = currentTime - arrivalTime[shortestJob];
                waitingTime[shortestJob] = turnaroundTime[shortestJob] - burstTime[shortestJob];
                executedProcesses++;
            }
        }
    }

    // Display Gantt chart
    printf("\nGantt Chart:\n");

    for (int i = 0; i < n; i++) {
        printf("| P%d ", processes[i]);
    }

    printf("|\n");
    printf("0");
    for(int i=0;i<n;i++)
{
	printf("   %d",turnaroundTime[i]);
}
    // Display turnaround time and waiting time for each process
    printf("\nProcess\tTurnaround Time\tWaiting Time\n");

    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\n", processes[i], turnaroundTime[i], waitingTime[i]);
    }

    // Calculate and display average turnaround time and average waiting time
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

        printf("Burst Time: ");
        scanf("%d", &burstTime[i]);
    }

    // Perform SJF scheduling
    performSJFScheduling(processes, n, arrivalTime, burstTime);

    return 0;
}


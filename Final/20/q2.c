
#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct n
{
    char pname[20];
    int arrivalT, burstT, startT, endT, waitT, tat;
    struct n *next;
} node;

node *head, *last;
int totalwt = 0;
int totaltat = 0;

void create(char pn[20], int at, int bt) 
{
    node *p;
    p = (node *)malloc(sizeof(node));
    strcpy(p->pname, pn);
    p->arrivalT = at;
    p->burstT = bt;
    p->next = NULL;
    if (head == NULL)
    {
        head = p;
    }

    else
    {
        last->next = p;
    }

    last = p;
}

void swap(node *p, node *q)
{ 
    char tem[20];
    int temp;
    strcpy(tem, p->pname);
    strcpy(p->pname, q->pname);
    strcpy(q->pname, tem);

    temp = p->arrivalT;
    p->arrivalT = q->arrivalT;
    q->arrivalT = temp;

    temp = p->burstT;
    p->burstT = q->burstT;
    q->burstT = temp;
}

void sort() 
{
    node *p, *q;
    int temp;
    int end = 0;
    char tem[20];
    for (p = head; p != NULL; p = p->next)
    {
        for (q = p->next; q != NULL; q = q->next)
        {
            if (p->arrivalT > q->arrivalT)
            {
                swap(p, q);
            }
        }
    }

    for (p = head; p != NULL; p = p->next)
    {
        for (q = p->next; q != NULL; q = q->next)
        {
            if (p == head)
            {
                end = p->burstT; 
            }
            else
            {
                if (q->arrivalT <= end && p->burstT > q->burstT) 
                {
                    swap(p, q);
                }
            }
        }
        end = end + p->burstT; 
    }
}

void calc() 
{
    node *p, *q;
    for (p = head; p != NULL; p = p->next)
    {
        if (p == head)
        {
            p->startT = p->arrivalT;       
            p->endT = p->burstT;           
            p->tat = p->endT - p->arrivalT; 
            p->waitT = p->tat - p->burstT;  
        }
        for (q = p->next; q != NULL; q = q->next)
        {

            if (q->arrivalT > p->endT)
            {
                q->startT = q->arrivalT;
            }
            else
                q->startT = p->endT;       
            q->endT = q->startT + q->burstT; 
            q->tat = q->endT - q->arrivalT;
            q->waitT = q->tat - q->burstT;

            break;
        }
    }
}

void print()
{
    node *p;
    printf("Pname\tArrival\tBurst\tStart\tend\ttat\twait\n");
    for (p = head; p != NULL; p = p->next)
    {
        printf("%s\t%d\t%d\t%d\t%d\t%d\t%d\n", p->pname, p->arrivalT, p->burstT, p->startT, p->endT, p->tat, p->waitT);
        totaltat += p->tat;
        totalwt += p->waitT;
    }
}

void printg() 
{

    node *current, *p = head, *q = head;

    for (current = head; current->next != NULL; current = current->next)
        ;

    printf("Exit Time -\t");
    printf("%d\t\t", p->startT);

    for (int i = 0; i <= current->endT; i++)
    {
        if (i == p->endT)
        {
            printf("%d\t\t", p->endT);
            p = p->next;
        }
    }
    printf("\n");
    printf("Pname\t\t");
    for (int i = 0; i <= current->endT; i++)
    {
        if (i == q->endT)
        {
            printf("\t%s\t", q->pname);
            q = q->next;
        }
    }

    printf("\n");
}

int main()
{
    int n, arrivalT, burstT;
    char pname[20];
    printf("How many process do you want to run ?");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter the process name, Arrival T, Burst T-:\n");
        scanf("%s%d%d", pname, &arrivalT, &burstT);
        create(pname, arrivalT, burstT);
    }

    sort();
    calc();
    print();
    printf("\nAverage Waiting time:%f", (float)totalwt / n);
    printf("\nAverage Turn Around Time:%f\n", (float)totaltat / n);
    printg();
}


/*
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
*/

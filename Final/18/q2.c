
#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct n   
{

    char pname[20];
    int accessTime, burstTime, exitTime, startTime, tat, waitTime;
    struct n *next;
} node;
static int totalwt = 0, totaltat = 0;
node *head, *last;

void create(char pname[20], int at, int bt)
{

    node *p;
    p = (node *)malloc(sizeof(node));
    strcpy(p->pname, pname);
    p->accessTime = at;
    p->burstTime = bt;
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

void sort() 
{

    node *p, *q;
    int t;
    char name[20];

    for (p = head; p != NULL; p = p->next) 
    {
        for (q = p->next; q != NULL; q = q->next)
        {
            if (p->accessTime > q->accessTime)           
            {
                strcpy(name, p->pname);
                strcpy(p->pname, q->pname);
                strcpy(q->pname, name);

                t = p->accessTime;
                p->accessTime = q->accessTime;
                q->accessTime = t;

                t = p->burstTime;
                p->burstTime = q->burstTime;
                q->burstTime = t;
            }
        }
    }
}

void calc()
{
    node *p, *q;
    for (p = head; p != NULL; p = p->next)
    {
        if (p == head)
        {
            p->startTime = p->accessTime; 
            p->exitTime = p->burstTime;     
            p->tat = p->exitTime - p->accessTime;
            p->waitTime = p->tat - p->burstTime;
        }
        for (q = p->next; q != NULL; q = q->next)
        {

            if (q->accessTime > p->exitTime)
            {
                q->startTime = q->accessTime;
            }
            else
                q->startTime = p->exitTime; 
            q->exitTime = q->startTime + q->burstTime;
            q->tat = q->exitTime - q->accessTime;
            q->waitTime = q->tat - q->burstTime;

            break;
        }
    }
}

void print() 
{
    node *p;
    printf("Pname\tArrival\tBurst\tStart\texit\ttat\twait\n");
    for (p = head; p != NULL; p = p->next)
    {
        printf("%s\t%d\t%d\t%d\t%d\t%d\t%d\n", p->pname, p->accessTime, p->burstTime, p->startTime, p->exitTime, p->tat, p->waitTime);
        totaltat += p->tat;
        totalwt += p->waitTime;
    }
}

void printg() 
{

    node *current, *p = head, *q = head;

    for (current = head; current->next != NULL; current = current->next)  
        ;

    printf("Exit Times -\t");
    printf("%d\t\t", p->startTime);

    for (int i = 0; i <= current->exitTime; i++)
    {
        if (i == p->exitTime)
        {

            printf("%d\t\t", p->exitTime);
            p = p->next;
        }
    }
    printf("\n");
    printf("Pname\t\t");
    for (int i = 0; i <= current->exitTime; i++)
    {
        if (i == q->exitTime)
        {

            printf("\t%s\t", q->pname);
            q = q->next;
        }
    }

    printf("\n");
}

int main(void)
{

    char pname[20];
    int at, bt, n;
    printf("How many processes?\n");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)                     
    {
        printf("Enter the process name and arrival time and burst time\n");
        scanf("%s%d%d", pname, &at, &bt);
        create(pname, at, bt);
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


void calculateTurnaroundTimeAndWaitingTime(int processes[], int n, int burstTime[], int waitingTime[], int turnaroundTime[]) 
{
   
    turnaroundTime[0] = burstTime[0];

   
    waitingTime[0] = 0;

    
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

   
    for (int i = 0; i < n; i++) {
        printf("| P%d ", processes[i]);
    }

    printf("|\n");

    
    printf("0");

    for (int i = 0; i < n; i++) {
        printf("      %d", turnaroundTime[i]);
    }

    printf("\n");
}


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

   
    calculateTurnaroundTimeAndWaitingTime(processes, n, burstTime, waitingTime, turnaroundTime);

    
    displayGanttChart(processes, n, burstTime, turnaroundTime);

   
    printf("\nProcess\tTurnaround Time\tWaiting Time\n");

    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\n", processes[i], turnaroundTime[i], waitingTime[i]);
    }

 
    displayAverageTimes(turnaroundTime, waitingTime, n);

    return 0;
}
*/

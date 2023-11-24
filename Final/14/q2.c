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
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;

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
        printf("Process P%d:\tTurnaround Time: %d\tWaiting Time: %d\n", processes[i].process_id,
               processes[i].turnaround_time, processes[i].waiting_time);
        total_turnaround_time += processes[i].turnaround_time;
        total_waiting_time += processes[i].waiting_time;
    }

    float avg_turnaround_time = total_turnaround_time / num_processes;
    float avg_waiting_time = total_waiting_time / num_processes;

    printf("\nAverage Turnaround Time: %.2f\nAverage Waiting Time: %.2f\n", avg_turnaround_time, avg_waiting_time);
}

int main() {
    int num_processes;

    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);

    if (num_processes <= 0 || num_processes > MAX_PROCESSES) {
        printf("Invalid number of processes. Please enter a number between 1 and %d.\n", MAX_PROCESSES);
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
*/


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


void swap (node *p,node *q) {
int temp;
char tem[20];

strcpy(tem,p->pname);
strcpy(p->pname,q->pname);
strcpy(q->pname,tem);

temp= p->arrivalT;
p->arrivalT=q->arrivalT;
q->arrivalT=temp;

temp=p->burstT;
p->burstT=q->burstT;
q->burstT=temp;
}

void sort () 
{
node *p,*q;
int end=0;
for(p=head;p!=NULL;p=p->next)
 {
for(q=p->next;q!=NULL;q=q->next) 
{
if(p->arrivalT > q->arrivalT) 
{
swap(p,q);
}   
}
end = end + p->burstT;
}
for(p=head;p!=NULL;p=p->next)
{
for(q=p->next;q!=NULL;q=q->next) 
{
if(p->burstT > q->burstT && p!=head)
{
swap(p,q);
}
else 
{
for(int i=p->arrivalT ;i < p->burstT ; i++) { 
if(i == q->arrivalT && ((p->burstT)-i) > q->burstT) 
{
end= end-((p->burstT)-i);
create(p->pname,end,((p->burstT)-i));
p->burstT=i;
}
}
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
p->startT = p->arrivalT;        
p->endT = p->burstT;            
p->tat = p->endT - p->arrivalT; 
p->waitT = p->tat - p->burstT; 
}
for (q = p->next; q != NULL; q = q->next)
{

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
for(p=head;p!=NULL;p=p->next) {
printf("%s\t%d\t%d\t%d\t%d\n",p->pname,p->arrivalT,p->burstT,p->startT,p->endT);
}
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
    //printf("\nAverage Waiting time:%f", (float)totalwt / n);
   // printf("\nAverage Turn Around Time:%f\n", (float)totaltat / n);
   // printg();
}


/*
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 10

typedef struct {
    int process_id;
    int arrival_time;
    int burst_time;
    int remaining_burst_time;
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
            if (processes[j].remaining_burst_time > processes[j + 1].remaining_burst_time) {
                swap(&processes[j], &processes[j + 1]);
            }
        }
    }
}

void sjf_scheduling(Process processes[], int num_processes) {
    int time = 0;
    int completed_processes = 0;

    while (completed_processes < num_processes) {
        for (int i = 0; i < num_processes; i++) {
            if (processes[i].arrival_time <= time && processes[i].remaining_burst_time > 0) {
                processes[i].remaining_burst_time--;
                time++;

                if (processes[i].remaining_burst_time == 0) {
                    completed_processes++;
                    processes[i].turnaround_time = time - processes[i].arrival_time;
                    processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
                }

                break;
            }
        }
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

        processes[i].remaining_burst_time = processes[i].burst_time;
    }

    sort_by_arrival_time(processes, num_processes);
    sjf_scheduling(processes, num_processes);
    print_gantt_chart(processes, num_processes);
    print_results(processes, num_processes);

    return 0;
}
*/



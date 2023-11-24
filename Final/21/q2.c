#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct process_info
{
	char pname[20];
	int at,bt,ct,bt1,p;
	struct process_info *next;
}NODE;

int n;
NODE *first,*last;

void accept_info()
{
	NODE *p;
	int i;

	printf("Enter no.of process:");
	scanf("%d",&n);

	for(i=0;i<n;i++)
	{
		p = (NODE*)malloc(sizeof(NODE));

		printf("Enter process name:");
		scanf("%s",p->pname);

		printf("Enter arrival time:");
		scanf("%d",&p->at);

		printf("Enter first CPU burst time:");
		scanf("%d",&p->bt);

		printf("Enter priority:");
		scanf("%d",&p->p);

		p->bt1 = p->bt;
		
		p->next = NULL;

		if(first==NULL)
			first=p;
		else
			last->next=p;

		last = p;
	}
}

void print_output()
{
	NODE *p;
	float avg_tat=0,avg_wt=0;

	printf("pname\tat\tbt\tp\ttct\ttat\twt\n");

	p = first;
	while(p!=NULL)
	{
		int tat = p->ct-p->at;
		int wt = tat-p->bt;
		
		avg_tat+=tat;
		avg_wt+=wt;

		printf("%s\t%d\t%d\t%d\t%d\t%d\t%d\n",
			p->pname,p->at,p->bt,p->p,p->ct,tat,wt);
		
		p=p->next;
	}

	printf("Avg TAT=%f\tAvg WT=%f\n",
			avg_tat/n,avg_wt/n);
}

void print_input()
{
	NODE *p;

	p = first;
	
	printf("pname\tat\tbt\tp\n");
	while(p!=NULL)
	{
		printf("%s\t%d\t%d\t%d\n",
			p->pname,p->at,p->bt1,p->p);
		p = p->next;
	}
}

void sort()
{
	NODE *p,*q;
	int t;
	char name[20];

	p = first;
	while(p->next!=NULL)
	{
		q=p->next;
		while(q!=NULL)
		{
			if(p->at > q->at)
			{
				strcpy(name,p->pname);
				strcpy(p->pname,q->pname);
				strcpy(q->pname,name);

				t = p->at;
				p->at = q->at;
				q->at = t;
				
				t = p->bt;
				p->bt = q->bt;
				q->bt = t;

				t = p->ct;
				p->ct = q->ct;
				q->ct = t;

				t = p->bt1;
				p->bt1 = q->bt1;
				q->bt1 = t;
			
				t = p->p;
				p->p = q->p;
				q->p = t;

			}

			q=q->next;
		}
	
		p=p->next;
	}
}

int time;

NODE * get_p()
{
	NODE *p,*min_p=NULL;
	int min=9999;

	p = first;
	while(p!=NULL)
	{
		if(p->at<=time && p->bt1!=0 && 
			p->p<min)
		{
			min = p->p;
			min_p = p;
		}
		p=p->next;
	}

	return min_p;
}

struct gantt_chart
{
	int start;
	char pname[30];
	int end;
}s[100],s1[100];

int k;

void pp()
{
	int prev=0,n1=0;
	NODE *p;

	while(n1!=n)
	{
		p = get_p();

		if(p==NULL)
		{
			time++;
			s[k].start = prev;
			strcpy(s[k].pname,"*");
			s[k].end = time;

			prev = time;
			k++;
		}
		else
		{
			time++;
			s[k].start = prev;
			strcpy(s[k].pname, p->pname);
			s[k].end = time;

			prev = time;
			k++;

			p->ct = time;
			p->bt1--;

			if(p->bt1==0) n1++;
		}

		print_input();	
		sort();
	}
}

void print_gantt_chart()
{
	int i,j,m;

	s1[0] = s[0];
	
	for(i=1,j=0;i<k;i++)
	{
		if(strcmp(s[i].pname,s1[j].pname)==0)
			s1[j].end = s[i].end;
		else
			s1[++j] = s[i];
	}

	printf("%d",s1[0].start);
	for(i=0;i<=j;i++)
	{
		m = (s1[i].end - s1[i].start);

		for(k=0;k<m/2;k++)
			printf("-");

		printf("%s",s1[i].pname);

		for(k=0;k<(m+1)/2;k++)
			printf("-");

		printf("%d",s1[i].end);
	}
}

int main()
{
	accept_info();
	sort();
	pp();
	print_output();
	print_gantt_chart();

	return 0;
}


/*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 10


struct Process {
    int process_id;
    int arrival_time;
    int cpu_burst;
    int priority;
    int waiting_time;
    int turnaround_time;
};


void preemptive_priority_scheduling(struct Process processes[], int n);

int main() {
    int n;
    struct Process processes[MAX_PROCESSES];

    
    srand(time(NULL));

  
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    
    printf("Enter arrival time, first CPU-burst, and priority for each process:\n");
    for (int i = 0; i < n; ++i) {
        processes[i].process_id = i + 1;
        printf("Process %d: ", i + 1);
        scanf("%d %d %d", &processes[i].arrival_time, &processes[i].cpu_burst, &processes[i].priority);
        processes[i].waiting_time = 0;
        processes[i].turnaround_time = 0;
    }

  
    preemptive_priority_scheduling(processes, n);

   
    double avg_waiting_time = 0, avg_turnaround_time = 0;
    for (int i = 0; i < n; ++i) {
        avg_waiting_time += processes[i].waiting_time;
        avg_turnaround_time += processes[i].turnaround_time;
    }
    avg_waiting_time /= n;
    avg_turnaround_time /= n;

    printf("\nAverage Waiting Time: %.2lf\n", avg_waiting_time);
    printf("Average Turnaround Time: %.2lf\n", avg_turnaround_time);

    return 0;
}

void preemptive_priority_scheduling(struct Process processes[], int n) {
    int time = 0; 
    int completed = 0; 
    int current_process = -1;

    printf("\nGantt Chart:\n");
    printf("--------------\n");

    while (completed < n) {
     
        int highest_priority = -1;
        for (int i = 0; i < n; ++i) {
            if (processes[i].arrival_time <= time && processes[i].turnaround_time == 0 &&
                (highest_priority == -1 || processes[i].priority < processes[highest_priority].priority)) {
                highest_priority = i;
            }
        }

    
        if (highest_priority != -1) {
            if (current_process != highest_priority) {
            
                if (current_process != -1) {
                    printf("| P%d ", processes[current_process].process_id);
                }
                current_process = highest_priority;
            }

         
            int next_burst = rand() % 10 + 1;
            printf("(%d) ", time);
            time += next_burst;

         
            processes[current_process].waiting_time += time - processes[current_process].arrival_time -
                                                       processes[current_process].turnaround_time;
            processes[current_process].turnaround_time += next_burst;

            completed++;
        } else {
          
            printf("| Idle ");
            time++;
        }
    }

  
    if (current_process != -1) {
        printf("| P%d ", processes[current_process].process_id);
    }

    printf("(%d) |\n", time);
}
*/

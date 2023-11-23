#include<stdio.h>
void calculateturnaroundtimeandwaitingtime(int processes[],int n,int bursttime[],int waitingtime[],int turnaroundtime[])
{
turnaroundtime[0]=bursttime[0];
waitingtime[0]=0;
for(int i=1;i<n;i++)
{
turnaroundtime[i]=turnaroundtime[i-1]+bursttime[i];
waitingtime[i]=turnaroundtime[i-1];
}
}

void displayganttchart(int processes[],int n,int bursttime[],int turnaroundtime[])
{
printf("\nGantt Chart: \n");
for(int i=0;i<n;i++)
{
printf("| P%d ",processes[i]);
}
printf("|\n");
printf("0");
for(int i=0;i<n;i++)
{
printf("   %d",turnaroundtime[i]);
}
printf("\n");
}


void displayaveragetimes(int waitingtime[],int turnaroundtime[],int n)
{
float avgtat=0,avgwt=0;
for(int i=0;i<n;i++)
{
avgtat +=turnaroundtime[i];
avgwt +=waitingtime[i];
}
avgtat /=n;
avgwt /=n;
printf("Average Turnaround Time=%.2f\n",avgtat);
printf("Average Waiting Time=%.2f\n\n\n",avgwt);
}


int main()
{
int n;
printf("Enter the no.of processes: ");
scanf("%d",&n);

int processes[n];
int arrivaltime[n];
int bursttime[n];
int waitingtime[n];
int turnaroundtime[n];

printf("Enter the arrival time and bursttime for each process...");
for(int i=0;i<n;i++)
{
printf("\n#Process%d:\n",i+1);
processes[i]=i+1;

printf("Enter arrival time: ");
scanf("%d",&arrivaltime[i]);

printf("Enter burst time: ");
scanf("%d",&bursttime[i]);
}
for(int i=0;i<n-1;i++)
{
for(int j=0;j<n-i-1;j++)
{
if(arrivaltime[j]>arrivaltime[j+1])
{

int tempat=arrivaltime[j];
arrivaltime[j]=arrivaltime[j+1];
arrivaltime[j+1]=tempat;

int tempbt=bursttime[j];
bursttime[j]=bursttime[j+1];
bursttime[j+1]=tempbt;

int temppc=processes[j];
processes[j]=processes[j+1];
processes[j+1]=temppc;
}
}
}

calculateturnaroundtimeandwaitingtime(processes,n,bursttime,waitingtime,turnaroundtime);
displayganttchart(processes,n,bursttime,turnaroundtime);
printf("\nProcess\tTurnaround Time\t Waiting Time\n");
for(int i=0;i<n;i++)
{
printf("P%d\t\t%d\t\t%d\n",processes[i],turnaroundtime[i],waitingtime[i]);
printf("\n");
}
displayaveragetimes(waitingtime,turnaroundtime,n);
return 0;
}





#include<stdio.h>
#include<stdlib.h>
int findmrupageindex(int *usagecounter,int n)
{
int minindex=0;
for(int i=0;i<n;i++)
{
if(usagecounter[i]<usagecounter[minindex])
{
minindex=i;
}
}
return minindex;
}

void simulatedemandpagingmru(int *referencestring,int referencestringlength,int n)
{
int frames[n];
int usagecounter[n];
int pagefaults=0;

for(int i=0;i<n;i++)
{
frames[i]=-1;
usagecounter[i]=0;
}
for(int i=0;i<referencestringlength;i++)
{
int page=referencestring[i];
int pagepresent=0;
for(int j=0;j<n;j++)
{
if(frames[j]==page)
{
pagepresent=1;
usagecounter[j]=i;
break;
}
}

if(!pagepresent)
{
int mruindex=findmrupageindex(usagecounter,n);
frames[mruindex]=page;
usagecounter[mruindex]=i;
pagefaults++;
}
printf("  %d",page);
}
printf("\n total no.of page faults=%d\n\n",pagefaults);
}

int main()
{
int referencestring[]={ 2,5,5,8,9,8,5,8,5,8,6,5,9,5,8,6};
int referencestringlength=sizeof(referencestring) / sizeof(referencestring[0]);
int n=3;
simulatedemandpagingmru(referencestring,referencestringlength,n);
return 0;
}




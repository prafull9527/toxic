#include<stdio.h>
#include<stdlib.h>
int findmrupageindex(int *counter,int n)
{
int minindex=0;
for(int i=1;i<n;i++)
{
if(counter[i]<counter[minindex])
{
minindex=i;
}
}
return minindex;
}


void simulatedemandpagingmru(int *referencestring,int referencestringlength,int n)
{
int frames[n];
int counter[n];
int pagefaults=0;
for(int i=0;i<n;i++)
{
frames[i]=-1;
counter[i]=0;
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
counter[j]++;
}
}
if(!pagepresent)
{
int mruindex=findmrupageindex(counter,n);
frames[mruindex]=page;
counter[mruindex]=1;
pagefaults++;
}
printf( "  %d",page);
}
printf("\n Total no.of page faults=%d\n\n",pagefaults);
}


int main ()
{
int referencestring[]={ 5,6,2,5,6,2,5,3,6,2,5,2,5,4,5,6,2};
int referencestringlength=sizeof(referencestring) / sizeof(referencestring[0]);
int n=3;
simulatedemandpagingmru(referencestring,referencestringlength,n);
return 0;
}




























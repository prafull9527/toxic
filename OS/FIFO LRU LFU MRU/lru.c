#include<stdio.h>
#include<stdlib.h>
int 
findLRUPageIndex(int *lastused,int n)
{
int minindex=0;
for(int i=1;i<n;i++)
{
if(lastused[i]<lastused[minindex])
{
minindex=i;
}
}
return minindex;
}

void simulatedemandpaginglru(int *referenceString,int referenceStringLength,int n)
{
int frames[n];
int lastused[n];
int pagefaults=0;
for(int i=0;i<n;i++)
{
frames[i]=-1;
lastused[i]=0;
}
for(int i=0;i<referenceStringLength;i++)
{
int page=referenceString[i];
int pagepresent=0;
for(int j=0;j<n;j++)
{
if(frames[j]==page)
{
pagepresent=1;
lastused[j]=i+1;
break;
}
}

if(!pagepresent)
{
int lruindex = findLRUPageIndex(lastused,n);
frames[lruindex]=page;
lastused[lruindex]=i+1;
pagefaults++;
}
printf("%d",page);
}
printf("\n total no.of page faults=%d\n",pagefaults);
}

int main()
{
int referenceString[] = {5,4,5,4,8,4,8,4,5,4,8,4,5,4};
int referenceStringLength= sizeof(referenceString) / sizeof(referenceString[0]);
int n=3;
simulatedemandpaginglru(referenceString,referenceStringLength,n);
return 0;
}













































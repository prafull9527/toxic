#include<stdio.h>
void simulatedemandpagingfifo(int *referencestring,int referencestringlength,int n)
{
int frames[n];
int framesindex=0;
int pagefaults=0;
for(int i=0;i<n;i++)
{
frames[i]=-1;
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
break;
}
}
if(!pagepresent)
{
frames[framesindex]=page;
framesindex=(framesindex + 1)%n;
pagefaults++;
}
printf(" %d ",page);
}
printf("\ntotal no.of pagefaults=%d\n",pagefaults);
}

int main()
{
int referencestring[]={ 2, 5, 8, 4, 6, 5, 8, 7, 8, 9, 5, 8, 7, 8, 5};
int referencestringlength=sizeof(referencestring) / sizeof(referencestring[0]); 
int n=3;
simulatedemandpagingfifo(referencestring,referencestringlength,n);
return 0;
}





/*SLIP NO.06
Q.1 Write the simulation program for demand paging and show the page
scheduling and total number of page faults according the MRU page
replacement algorithm. Assume the memory of n frames.
Reference String
: 8, 5, 7, 8, 5, 7, 2, 3, 7, 3, 5, 9, 4, 6, 2*/
/*
#include <stdio.h>
#include <stdlib.h>

// Function to find the index of the most recently used page in frames
int findMRUPageIndex(int *usageCounter, int n) {
    int maxIndex = 0;
    for (int i = 1; i < n; i++) {
        if (usageCounter[i] > usageCounter[maxIndex]) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

// Function to simulate demand paging with MRU page replacement algorithm
void simulateDemandPagingMRU(int *referenceString, int referenceStringLength, int n) {
    int frames[n];
    int usageCounter[n]; // To keep track of the usage counter for each page in frames
    int pageFaults = 0;

    // Initialize frames and counters
    for (int i = 0; i < n; i++) {
        frames[i] = -1; // -1 indicates an empty frame
        usageCounter[i] = 0;
    }

    // Simulate demand paging
    for (int i = 0; i < referenceStringLength; i++) {
        int page = referenceString[i];

        // Check if the page is present in frames
        int pagePresent = 0;
        for (int j = 0; j < n; j++) {
            if (frames[j] == page) {
                pagePresent = 1;
                usageCounter[j] = i; // Update the usage counter for the accessed page
                break;
            }
        }

        // If the page is not present in frames, handle page fault
        if (!pagePresent) {
            // Page fault, replace the most recently used page in frames
            int mruIndex = findMRUPageIndex(usageCounter, n);
            frames[mruIndex] = page;
            usageCounter[mruIndex] = i; // Update the usage counter for the newly loaded page
            pageFaults++;
        }

        // Print the current page scheduling order
        printf("%d ", page);
    }

    printf("\nTotal Page Faults: %d\n", pageFaults);
}

int main() {
    // Reference String: 8, 5, 7, 8, 5, 7, 2, 3, 7, 3, 5, 9, 4, 6, 2
    int referenceString[] = {8, 5, 7, 8, 5, 7, 2, 3, 7, 3, 5, 9, 4, 6, 2};
    int referenceStringLength = sizeof(referenceString) / sizeof(referenceString[0]);

    // Number of frames in memory
    int n = 3;

    // Simulate demand paging with MRU page replacement algorithm
    simulateDemandPagingMRU(referenceString, referenceStringLength, n);

    return 0;
}



*/
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




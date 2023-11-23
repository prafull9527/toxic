OS SOLVED SLIPS BY PRAFULL CHAVAN

/*SLIP NO.01
Q)WRITE THE SIMULATION PROGRAM TO IMPLEMENT DEMAND PAGING USING LFU PAGE REPLACEMENT ALGORITHM. ASSUME THE MEMORY OF "n" FRAMES. SHOW THE CONTENTS OF PAGE AFTER EVERY PAGE REPLACEMENT IN A FRAME AND AT END SHOW THE TOTAL NUMBER OF PAGE FAULTS ACCORDINGLY. INPUT THE FOLLOWING PAGE REFERENCE STRING.

PAGE REFERENCE STRING - 3,4,5,4,3,4,7,2,4,5,6,7,2,4,6.

--->

*/
#include<stdio.h>
#define MAX 20

int frames[MAX],ref[MAX],mem[MAX][MAX],faults,
 sp,m,n,count[MAX];

void accept()
{
 int i;

 printf("Enter no.of frames:");
 scanf("%d", &n);

 printf("Enter no.of references:");
 scanf("%d", &m);

 printf("Enter reference string:\n");
  scanf("%d", &sp);
 for(i=0;i<m;i++)
 {
  printf("[%d]=",i);
  scanf("%d",&ref[i]);
 }
}

void disp()
{
 int i,j;

 for(i=0;i<m;i++)
  printf("%3d",ref[i]);

 printf("\n\n");

 for(i=0;i<n;i++)
 {
  for(j=0;j<m;j++)
  {
   if(mem[i][j])
    printf("%3d",mem[i][j]);
   else
    printf("   ");
  }
  printf("\n");
 }

 printf("Total Page Faults: %d\n",faults);
}

int search(int pno)
{
 int i;

 for(i=0;i<n;i++)
 {
  if(frames[i]==pno)
   return i;
 }

 return -1;
}

int get_lfu(int sp)
{
 int i,min_i,min=9999;

 i=sp;
 do
 {
  if(count[i]<min)
  {
   min = count[i];
   min_i = i;
  }
  i=(i+1)%n;
 }while(i!=sp);

 return min_i;
}


void lfu()
{
 int i,j,k;

 for(i=0;i<m && sp<n;i++)
 {
  k=search(ref[i]);
  if(k==-1)
  {
   frames[sp]=ref[i];
   count[sp]++;
   faults++;
   sp++;

   for(j=0;j<n;j++)
    mem[j][i]=frames[j];
  }
  else
   count[k]++;
  
 }

 sp=0;
 for(;i<m;i++)
 {
  k = search(ref[i]);
  if(k==-1)
  {
   sp = get_lfu(sp);
   frames[sp] = ref[i];
   count[sp]=1;
   faults++;
   sp = (sp+1)%n;

   for(j=0;j<n;j++)
    mem[j][i] = frames[j];
  }
  else
   count[k]++;
 }
}
      

int main()
{
 accept();
 lfu();
 disp();

 return 0;
}


/*SLIP NO.02
Q.1 Write the simulation program for demand paging and show the page
scheduling and total number of page faults according the FIFO page
replacement algorithm. Assume the memory of n frames.
Reference String
: 3, 4, 5, 6, 3, 4, 7, 3, 4, 5, 6, 7, 2, 4, 6*/

#include <stdio.h>
#include <stdlib.h>

// Function to check if a page is present in memory
int isPagePresent(int page, int *frames, int n) {
    for (int i = 0; i < n; i++) {
        if (frames[i] == page) {
            return 1; // Page is present
        }
    }
    return 0; // Page is not present
}

// Function to find the index of the oldest page in frames
int findOldestPageIndex(int *arrival, int n) {
    int oldestIndex = 0;
    for (int i = 1; i < n; i++) {
        if (arrival[i] < arrival[oldestIndex]) {
            oldestIndex = i;
        }
    }
    return oldestIndex;
}

// Function to simulate demand paging with FIFO page replacement algorithm
void simulateDemandPaging(int *referenceString, int referenceStringLength, int n) {
    int frames[n];
    int arrival[n]; // To keep track of the arrival time of each page in frames
    int pageFaults = 0;

    // Initialize frames and arrival times
    for (int i = 0; i < n; i++) {
        frames[i] = -1; // -1 indicates an empty frame
        arrival[i] = 0;
    }

    // Simulate demand paging
    for (int i = 0; i < referenceStringLength; i++) {
        int page = referenceString[i];

        // Check if the page is present in frames
        if (!isPagePresent(page, frames, n)) {
            // Page fault, replace the oldest page in frames
            int oldestIndex = findOldestPageIndex(arrival, n);
            frames[oldestIndex] = page;
            arrival[oldestIndex] = i + 1; // Update arrival time
            pageFaults++;
        }

        // Print the current page scheduling order
        printf("%d ", page);
    }

    printf("\nTotal Page Faults: %d\n", pageFaults);
}

int main() {
    // Reference String: 3, 4, 5, 6, 3, 4, 7, 3, 4, 5, 6, 7, 2, 4, 6
    int referenceString[] = {3, 4, 5, 6, 3, 4, 7, 3, 4, 5, 6, 7, 2, 4, 6};
    int referenceStringLength = sizeof(referenceString) / sizeof(referenceString[0]);

    // Number of frames in memory
    int n = 3;

    // Simulate demand paging with FIFO page replacement algorithm
    simulateDemandPaging(referenceString, referenceStringLength, n);

    return 0;
}




/*SLIP NO.03
Q.1 Write the simulation program to implement demand paging and show the page
scheduling and total number of page faults according to the LRU (using
counter method) page replacement algorithm. Assume the memory of n
frames.
Reference String : 3,5,7,2,5,1,2,3,1,3,5,3,1,6,2*/

#include <stdio.h>
#include <stdlib.h>

// Function to find the index of the least recently used page in frames
int findLRUPageIndex(int *counter, int n) {
    int minIndex = 0;
    for (int i = 1; i < n; i++) {
        if (counter[i] < counter[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex;
}

// Function to simulate demand paging with LRU page replacement algorithm (using counter method)
void simulateDemandPagingLRU(int *referenceString, int referenceStringLength, int n) {
    int frames[n];
    int counter[n]; // To keep track of the usage counter for each page in frames
    int pageFaults = 0;

    // Initialize frames and counters
    for (int i = 0; i < n; i++) {
        frames[i] = -1; // -1 indicates an empty frame
        counter[i] = 0;
    }

    // Simulate demand paging
    for (int i = 0; i < referenceStringLength; i++) {
        int page = referenceString[i];

        // Check if the page is present in frames
        int pagePresent = 0;
        for (int j = 0; j < n; j++) {
            if (frames[j] == page) {
                pagePresent = 1;
                counter[j]++;
            } else {
                counter[j] >>= 1; // Right shift to simulate aging (update counter for non-referenced pages)
            }
        }

        // If the page is not present in frames, handle page fault
        if (!pagePresent) {
            // Page fault, replace the least recently used page in frames
            int lruIndex = findLRUPageIndex(counter, n);
            frames[lruIndex] = page;
            counter[lruIndex] = 1; // Set the counter to 1 for the newly loaded page
            pageFaults++;
        }

        // Print the current page scheduling order
        printf("%d ", page);
    }

    printf("\nTotal Page Faults: %d\n", pageFaults);
}

int main() {
    // Reference String: 3, 5, 7, 2, 5, 1, 2, 3, 1, 3, 5, 3, 1, 6, 2
    int referenceString[] = {3, 5, 7, 2, 5, 1, 2, 3, 1, 3, 5, 3, 1, 6, 2};
    int referenceStringLength = sizeof(referenceString) / sizeof(referenceString[0]);

    // Number of frames in memory
    int n = 3;

    // Simulate demand paging with LRU page replacement algorithm (using counter method)
    simulateDemandPagingLRU(referenceString, referenceStringLength, n);

    return 0;
}



Q.1)
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<stdlib.h>

void count(char *cm,char *file){
    char cd;
    int fn =open(file,O_RDONLY);
    int lineCount=0,wordCount=0,charCount=0;

    while(read(fn,&cd,1)>0){
        if(cd=='\n')
        lineCount++;
       else if(cd==' ')
        wordCount++;
        else
        charCount++;        
    }
    if(strcmp(cm,"c")==0){
        printf("The number of characters in the file are %d\n",charCount);
    }
    if(strcmp(cm,"w")==0){
        printf("The number of words in the file are %d\t",wordCount);
    }
    if(strcmp(cm,"l")==0){
        printf("The number of lines in the file are %d\n",lineCount);
    }
}

int main(void)
{
    char cmd[80],op1[20],op2[20],op3[30];
    while(1){
        printf("\n MyShell $ ");
        scanf("%c",cmd);
        int pid=fork();
        if(pid==-1){
            printf("Error\n");
        }
        else if(pid > 1){
            wait(NULL);
        }
        else{

        int n=sscanf(cmd,"%s %s %s",op1,op2,op3);
        if(strcmp(op1,"count")==0){
            count(op2,op3);
            exit(0);
        }

        }
    }
}



/*SLIP NO.04
Q.1 Write the simulation program for demand paging and show the page
scheduling and total number of page faults according the MFU page
replacement algorithm. Assume the memory of n frames.
Reference String
: 8, 5, 7, 8, 5, 7, 2, 3, 7, 3, 5, 9, 4, 6, 2*/


#include <stdio.h>
#include <stdlib.h>

// Function to find the index of the most frequently used page in frames
int findMFUPageIndex(int *counter, int n) {
    int maxIndex = 0;
    for (int i = 1; i < n; i++) {
        if (counter[i] > counter[maxIndex]) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

// Function to simulate demand paging with MFU page replacement algorithm
void simulateDemandPagingMFU(int *referenceString, int referenceStringLength, int n) {
    int frames[n];
    int counter[n]; // To keep track of the usage counter for each page in frames
    int pageFaults = 0;

    // Initialize frames and counters
    for (int i = 0; i < n; i++) {
        frames[i] = -1; // -1 indicates an empty frame
        counter[i] = 0;
    }

    // Simulate demand paging
    for (int i = 0; i < referenceStringLength; i++) {
        int page = referenceString[i];

        // Check if the page is present in frames
        int pagePresent = 0;
        for (int j = 0; j < n; j++) {
            if (frames[j] == page) {
                pagePresent = 1;
                counter[j]++;
            }
        }

        // If the page is not present in frames, handle page fault
        if (!pagePresent) {
            // Page fault, replace the most frequently used page in frames
            int mfuIndex = findMFUPageIndex(counter, n);
            frames[mfuIndex] = page;
            counter[mfuIndex] = 1; // Set the counter to 1 for the newly loaded page
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

    // Simulate demand paging with MFU page replacement algorithm
    simulateDemandPagingMFU(referenceString, referenceStringLength, n);

    return 0;
}




/*SLIP NO.05
Q.1 Write the simulation program for demand paging and show the page
scheduling and total number of page faults according the optimal page
replacement algorithm. Assume the memory of n frames.
Reference String
: 8, 5, 7, 8, 5, 7, 2, 3, 7, 3, 5, 9, 4, 6, 2*/


#include <stdio.h>
#include <stdlib.h>

// Function to find the index of the page that will not be used for the longest period in the future
int findOptimalPageIndex(int *pages, int n, int *referenceString, int referenceStringLength, int currentPosition) {
    int farthestIndex = -1;
    int farthestDistance = -1;

    for (int i = 0; i < n; i++) {
        int nextPage = pages[i];
        int nextOccurrence = -1;

        // Find the next occurrence of the current page in the reference string
        for (int j = currentPosition + 1; j < referenceStringLength; j++) {
            if (referenceString[j] == nextPage) {
                nextOccurrence = j;
                break;
            }
        }

        // If the page will not be used in the future, select it for replacement
        if (nextOccurrence == -1) {
            return i;
        }

        // Update the farthest distance if the current page's next occurrence is farther
        if (nextOccurrence > farthestDistance) {
            farthestDistance = nextOccurrence;
            farthestIndex = i;
        }
    }

    return farthestIndex;
}

// Function to simulate demand paging with optimal page replacement algorithm
void simulateDemandPagingOptimal(int *referenceString, int referenceStringLength, int n) {
    int frames[n];
    int pageFaults = 0;

    // Initialize frames
    for (int i = 0; i < n; i++) {
        frames[i] = -1; // -1 indicates an empty frame
    }

    // Simulate demand paging
    for (int i = 0; i < referenceStringLength; i++) {
        int page = referenceString[i];

        // Check if the page is present in frames
        int pagePresent = 0;
        for (int j = 0; j < n; j++) {
            if (frames[j] == page) {
                pagePresent = 1;
                break;
            }
        }

        // If the page is not present in frames, handle page fault
        if (!pagePresent) {
            // Page fault, replace a page using the optimal algorithm
            int pageToReplace = findOptimalPageIndex(frames, n, referenceString, referenceStringLength, i);
            frames[pageToReplace] = page;
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

    // Simulate demand paging with optimal page replacement algorithm
    simulateDemandPagingOptimal(referenceString, referenceStringLength, n);

    return 0;
}

/*SLIP NO.06
Q.1 Write the simulation program for demand paging and show the page
scheduling and total number of page faults according the MRU page
replacement algorithm. Assume the memory of n frames.
Reference String
: 8, 5, 7, 8, 5, 7, 2, 3, 7, 3, 5, 9, 4, 6, 2*/

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




/*SLIP NO.07
Q.1 Write the simulation program for demand paging and show the page
scheduling and total number of page faults according the Optimal page
replacement algorithm. Assume the memory of n frames.
Reference String
: 7, 5, 4, 8, 5, 7, 2, 3, 1, 3, 5, 9, 4, 6, 2*/


#include <stdio.h>
#include <stdlib.h>

// Function to find the index of the page that will not be used for the longest period in the future
int findOptimalPageIndex(int *pages, int n, int *referenceString, int referenceStringLength, int currentPosition) {
    int farthestIndex = -1;
    int farthestDistance = -1;

    for (int i = 0; i < n; i++) {
        int nextPage = pages[i];
        int nextOccurrence = -1;

        // Find the next occurrence of the current page in the reference string
        for (int j = currentPosition + 1; j < referenceStringLength; j++) {
            if (referenceString[j] == nextPage) {
                nextOccurrence = j;
                break;
            }
        }

        // If the page will not be used in the future, select it for replacement
        if (nextOccurrence == -1) {
            return i;
        }

        // Update the farthest distance if the current page's next occurrence is farther
        if (nextOccurrence > farthestDistance) {
            farthestDistance = nextOccurrence;
            farthestIndex = i;
        }
    }

    return farthestIndex;
}

// Function to simulate demand paging with Optimal page replacement algorithm
void simulateDemandPagingOptimal(int *referenceString, int referenceStringLength, int n) {
    int frames[n];
    int pageFaults = 0;

    // Initialize frames
    for (int i = 0; i < n; i++) {
        frames[i] = -1; // -1 indicates an empty frame
    }

    // Simulate demand paging
    for (int i = 0; i < referenceStringLength; i++) {
        int page = referenceString[i];

        // Check if the page is present in frames
        int pagePresent = 0;
        for (int j = 0; j < n; j++) {
            if (frames[j] == page) {
                pagePresent = 1;
                break;
            }
        }

        // If the page is not present in frames, handle page fault
        if (!pagePresent) {
            // Page fault, replace a page using the Optimal algorithm
            int pageToReplace = findOptimalPageIndex(frames, n, referenceString, referenceStringLength, i);
            frames[pageToReplace] = page;
            pageFaults++;
        }

        // Print the current page scheduling order
        printf("%d ", page);
    }

    printf("\nTotal Page Faults: %d\n", pageFaults);
}

int main() {
    // Reference String: 7, 5, 4, 8, 5, 7, 2, 3, 1, 3, 5, 9, 4, 6, 2
    int referenceString[] = {7, 5, 4, 8, 5, 7, 2, 3, 1, 3, 5, 9, 4, 6, 2};
    int referenceStringLength = sizeof(referenceString) / sizeof(referenceString[0]);

    // Number of frames in memory
    int n = 3;

    // Simulate demand paging with Optimal page replacement algorithm
    simulateDemandPagingOptimal(referenceString, referenceStringLength, n);

    return 0;
}



/*SLIP NO.08
Q.1 Write the simulation program for demand paging and show the page
scheduling and total number of page faults according the LRU page
replacement algorithm. Assume the memory of n frames.
Reference String
: 8, 5, 7, 8, 5, 7, 2, 3, 7, 3, 5, 9, 4, 6, 2*/


#include <stdio.h>
#include <stdlib.h>

// Function to find the index of the least recently used page in frames
int findLRUPageIndex(int *lastUsed, int n) {
    int minIndex = 0;
    for (int i = 1; i < n; i++) {
        if (lastUsed[i] < lastUsed[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex;
}

// Function to simulate demand paging with LRU page replacement algorithm
void simulateDemandPagingLRU(int *referenceString, int referenceStringLength, int n) {
    int frames[n];
    int lastUsed[n]; // To keep track of the last used time for each page in frames
    int pageFaults = 0;

    // Initialize frames and lastUsed times
    for (int i = 0; i < n; i++) {
        frames[i] = -1; // -1 indicates an empty frame
        lastUsed[i] = 0;
    }

    // Simulate demand paging
    for (int i = 0; i < referenceStringLength; i++) {
        int page = referenceString[i];

        // Check if the page is present in frames
        int pagePresent = 0;
        for (int j = 0; j < n; j++) {
            if (frames[j] == page) {
                pagePresent = 1;
                lastUsed[j] = i + 1; // Update the last used time for the accessed page
                break;
            }
        }

        // If the page is not present in frames, handle page fault
        if (!pagePresent) {
            // Page fault, replace the least recently used page in frames
            int lruIndex = findLRUPageIndex(lastUsed, n);
            frames[lruIndex] = page;
            lastUsed[lruIndex] = i + 1; // Update the last used time for the newly loaded page
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

    // Simulate demand paging with LRU page replacement algorithm
    simulateDemandPagingLRU(referenceString, referenceStringLength, n);

    return 0;
}


/*SLIP NO.09
Q.1 Write the simulation program for demand paging and show the page
scheduling and total number of page faults according the FIFO page
replacement algorithm. Assume the memory of n frames.
Reference String
: 8, 5, 7, 8, 5, 7, 2, 3, 7, 3, 5, 9, 4, 6, 2*/


#include <stdio.h>
#include <stdlib.h>

// Function to simulate demand paging with FIFO page replacement algorithm
void simulateDemandPagingFIFO(int *referenceString, int referenceStringLength, int n) {
    int frames[n];
    int frameIndex = 0; // Index to keep track of the next frame to be replaced in FIFO order
    int pageFaults = 0;

    // Initialize frames
    for (int i = 0; i < n; i++) {
        frames[i] = -1; // -1 indicates an empty frame
    }

    // Simulate demand paging
    for (int i = 0; i < referenceStringLength; i++) {
        int page = referenceString[i];

        // Check if the page is present in frames
        int pagePresent = 0;
        for (int j = 0; j < n; j++) {
            if (frames[j] == page) {
                pagePresent = 1;
                break;
            }
        }

        // If the page is not present in frames, handle page fault
        if (!pagePresent) {
            // Page fault, replace the oldest page in frames in FIFO order
            frames[frameIndex] = page;
            frameIndex = (frameIndex + 1) % n; // Move to the next frame in FIFO order
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

    // Simulate demand paging with FIFO page replacement algorithm
    simulateDemandPagingFIFO(referenceString, referenceStringLength, n);

    return 0;
}


/*SLIP N0.10
Q.1 Write the simulation program for demand paging and show the page
scheduling and total number of page faults according the FIFO page
replacement algorithm. Assume the memory of n frames.
Reference String
: 2, 4, 5, 6, 9, 4, 7, 3, 4, 5, 6, 7, 2, 4, 7, 1
*/



#include <stdio.h>
#include <stdlib.h>

#define MAX_FRAMES 10

typedef struct {
    int page;
    int in_memory;
} PageEntry;

void initialize_memory(PageEntry memory[], int num_frames) {
    for (int i = 0; i < num_frames; i++) {
        memory[i].page = -1;
        memory[i].in_memory = 0;
    }
}

void print_memory(PageEntry memory[], int num_frames) {
    printf("Memory: ");
    for (int i = 0; i < num_frames; i++) {
        if (memory[i].page != -1) {
            printf("%d ", memory[i].page);
        } else {
            printf("- ");
        }
    }
    printf("\n");
}

int is_page_in_memory(PageEntry memory[], int num_frames, int page) {
    for (int i = 0; i < num_frames; i++) {
        if (memory[i].page == page) {
            return 1;
        }
    }
    return 0;
}

void page_fault(PageEntry memory[], int num_frames, int page, int *faults, int *next_position) {
    if (*next_position == num_frames) {
        *next_position = 0;
    }

    if (memory[*next_position].in_memory) {
        *faults += 1;
    }

    memory[*next_position].page = page;
    memory[*next_position].in_memory = 1;
    *next_position += 1;
}

void simulate_fifo(int reference_string[], int length, int num_frames) {
    PageEntry memory[MAX_FRAMES];
    int faults = 0;
    int next_position = 0;

    initialize_memory(memory, num_frames);

    printf("Simulation with FIFO Page Replacement Algorithm:\n");
    printf("Reference String: ");
    for (int i = 0; i < length; i++) {
        printf("%d ", reference_string[i]);
    }
    printf("\nNumber of Frames: %d\n", num_frames);

    for (int i = 0; i < length; i++) {
        int page = reference_string[i];

        if (!is_page_in_memory(memory, num_frames, page)) {
            page_fault(memory, num_frames, page, &faults, &next_position);
        }

        printf("Accessing Page %d\n", page);
        print_memory(memory, num_frames);
    }

    printf("\nTotal Number of Page Faults: %d\n", faults);
}

int main() {
    int reference_string[] = {2, 4, 5, 6, 9, 4, 7, 3, 4, 5, 6, 7, 2, 4, 7, 1};
    int length = sizeof(reference_string) / sizeof(reference_string[0]);
    int num_frames = 3;

    simulate_fifo(reference_string, length, num_frames);

    return 0;
}



SLIP NO.11
/*Q.1 Write the simulation program for demand paging and show the page
scheduling and total number of page faults according the LFU page
replacement algorithm. Assume the memory of n frames.
Reference String
: 3, 4, 5, 6, 3, 4, 7, 3, 4, 5, 6, 7, 2, 4, 6
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_FRAMES 10

typedef struct {
    int page;
    int frequency;
} PageEntry;

typedef struct {
    PageEntry entries[MAX_FRAMES];
    int count;
} PageTable;

int find_page(PageTable *table, int page) {
    for (int i = 0; i < table->count; i++) {
        if (table->entries[i].page == page) {
            return i;
        }
    }
    return -1;
}

int find_lfu_page(PageTable *table) {
    int min_index = 0;
    for (int i = 1; i < table->count; i++) {
        if (table->entries[i].frequency < table->entries[min_index].frequency) {
            min_index = i;
        }
    }
    return min_index;
}

void print_memory(PageTable *table) {
    printf("Memory: ");
    for (int i = 0; i < table->count; i++) {
        printf("%d ", table->entries[i].page);
    }
    printf("\n");
}

void simulate(int reference_string[], int length, int num_frames) {
    PageTable table;
    table.count = 0;

    int page_faults = 0;

    for (int i = 0; i < length; i++) {
        int page = reference_string[i];

        int index = find_page(&table, page);

        if (index == -1) {
            // Page fault
            page_faults++;

            if (table.count < num_frames) {
                // There is space in memory
                table.entries[table.count].page = page;
                table.entries[table.count].frequency = 1;
                table.count++;
            } else {
                // LFU Page Replacement
                int lfu_index = find_lfu_page(&table);
                table.entries[lfu_index].page = page;
                table.entries[lfu_index].frequency = 1;
            }
        } else {
            // Page hit, increase frequency
            table.entries[index].frequency++;
        }

        printf("Accessing Page %d\n", page);
        print_memory(&table);
    }

    printf("\nTotal Number of Page Faults: %d\n", page_faults);
}

int main() {
    int reference_string[] = {3, 4, 5, 6, 3, 4, 7, 3, 4, 5, 6, 7, 2, 4, 6};
    int length = sizeof(reference_string) / sizeof(reference_string[0]);

    int num_frames = 3;

    simulate(reference_string, length, num_frames);

    return 0;
}



SLIP NO.12
/*Q.1 Write the simulation program for demand paging and show the page
scheduling and total number of page faults according the LRU page
replacement algorithm. Assume the memory of n frames.
Reference String
: 3, 4, 5, 6, 3, 4, 7, 3, 4, 5, 6, 7, 2, 4, 6*/
#include <stdio.h>
#include <stdlib.h>

#define MAX_FRAMES 10

typedef struct {
    int page;
    int last_used;
} PageEntry;

typedef struct {
    PageEntry entries[MAX_FRAMES];
    int count;
} PageTable;

int find_page(PageTable *table, int page) {
    for (int i = 0; i < table->count; i++) {
        if (table->entries[i].page == page) {
            return i;
        }
    }
    return -1;
}

int find_lru_page(PageTable *table) {
    int min_index = 0;
    for (int i = 1; i < table->count; i++) {
        if (table->entries[i].last_used < table->entries[min_index].last_used) {
            min_index = i;
        }
    }
    return min_index;
}

void print_memory(PageTable *table) {
    printf("Memory: ");
    for (int i = 0; i < table->count; i++) {
        printf("%d ", table->entries[i].page);
    }
    printf("\n");
}

void update_last_used(PageTable *table, int index) {
    table->entries[index].last_used = 0;
    for (int i = 0; i < table->count; i++) {
        if (i != index) {
            table->entries[i].last_used++;
        }
    }
}

void simulate(int reference_string[], int length, int num_frames) {
    PageTable table;
    table.count = 0;

    int page_faults = 0;

    for (int i = 0; i < length; i++) {
        int page = reference_string[i];

        int index = find_page(&table, page);

        if (index == -1) {
            // Page fault
            page_faults++;

            if (table.count < num_frames) {
                // There is space in memory
                table.entries[table.count].page = page;
                table.entries[table.count].last_used = 0;
                table.count++;
            } else {
                // LRU Page Replacement
                int lru_index = find_lru_page(&table);
                table.entries[lru_index].page = page;
                update_last_used(&table, lru_index);
            }
        } else {
            // Page hit, update last used
            update_last_used(&table, index);
        }

        printf("Accessing Page %d\n", page);
        print_memory(&table);
    }

    printf("\nTotal Number of Page Faults: %d\n", page_faults);
}

int main() {
    int reference_string[] = {3, 4, 5, 6, 3, 4, 7, 3, 4, 5, 6, 7, 2, 4, 6};
    int length = sizeof(reference_string) / sizeof(reference_string[0]);

    int num_frames = 3;

    simulate(reference_string, length, num_frames);

    return 0;
}



SLIP NO.13
/*Q.1 Write a C program to implement the shell which displays the command
prompt “myshell$”. It accepts the command, tokenize the command line and
execute it by creating the child process. Also implement the additional
command ‘typeline’ as
typeline -a
filename :- To print all lines in the file*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_TOKENS 100

void execute_command(char *tokens[]) {
    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Child process
        execvp(tokens[0], tokens);
        perror("execvp");
        exit(EXIT_FAILURE);
    } else {
        // Parent process
        waitpid(pid, NULL, 0);
    }
}

void typeline_command(char *filename, int append) {
    FILE *file;
    char line[MAX_COMMAND_LENGTH];

    if (append) {
        file = fopen(filename, "a");
    } else {
        file = fopen(filename, "r");
    }

    if (file == NULL) {
        perror("fopen");
        return;
    }

    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
    }

    fclose(file);
}

int main() {
    char command[MAX_COMMAND_LENGTH];
    char *tokens[MAX_TOKENS];
    char *token;

    while (1) {
        printf("myshell$ ");
        fgets(command, sizeof(command), stdin);

        // Remove newline character
        command[strcspn(command, "\n")] = '\0';

        // Tokenize the command
        int token_count = 0;
        token = strtok(command, " ");

        while (token != NULL) {
            tokens[token_count++] = token;
            token = strtok(NULL, " ");
        }

        // Check if the 'typeline' command is used
        if (token_count >= 2 && strcmp(tokens[0], "typeline") == 0) {
            if (strcmp(tokens[1], "-a") == 0 && token_count >= 3) {
                // 'typeline -a filename'
                typeline_command(tokens[2], 1);
            } else {
                // 'typeline filename'
                typeline_command(tokens[1], 0);
            }
        } else {
            // Execute the command
            tokens[token_count] = NULL; // Null-terminate the array
            execute_command(tokens);
        }
    }

    return 0;
}



/*Q.2 Write the simulation program for Round Robin scheduling for given time
quantum. The arrival time and first CPU-burst of different jobs should be input
to the system. Accept no. of Processes, arrival time and burst time. The output
should give the Gantt chart, turnaround time and waiting time for each
process. Also display the average turnaround time and average waiting time.*/

#include <stdio.h>
#define MAX_PROCESSES 10

typedef struct {
    int arrival_time;
    int burst_time;
    int remaining_time;
    int turnaround_time;
    int waiting_time;
    int is_completed;
} Process;

void round_robin(Process processes[], int num_processes, int time_quantum) {
    int remaining_processes = num_processes;
    int time = 0;

    while (remaining_processes > 0) {
        for (int i = 0; i < num_processes; i++) {
            if (processes[i].is_completed) {
                continue;
            }

            int current_burst = (processes[i].remaining_time < time_quantum) ? processes[i].remaining_time : time_quantum;

            processes[i].remaining_time -= current_burst;
            time += current_burst;

            printf("| P%d ", i + 1);

            if (processes[i].remaining_time == 0) {
                processes[i].turnaround_time = time - processes[i].arrival_time;
                processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
                processes[i].is_completed = 1;
                remaining_processes--;
            }
        }
    }
}

int main() {
    int num_processes;
    int time_quantum;

    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);

    if (num_processes <= 0 || num_processes > MAX_PROCESSES) {
        printf("Invalid number of processes. Please enter a number between 1 and %d.\n", MAX_PROCESSES);
        return 1;
    }

    printf("Enter the time quantum: ");
    scanf("%d", &time_quantum);

    if (time_quantum <= 0) {
        printf("Invalid time quantum. Please enter a positive number.\n");
        return 1;
    }

    Process processes[MAX_PROCESSES];

    for (int i = 0; i < num_processes; i++) {
        printf("Enter arrival time for process P%d: ", i + 1);
        scanf("%d", &processes[i].arrival_time);

        printf("Enter burst time for process P%d: ", i + 1);
        scanf("%d", &processes[i].burst_time);

        processes[i].remaining_time = processes[i].burst_time;
        processes[i].is_completed = 0;
    }

    printf("\nGantt Chart:\n|");

    round_robin(processes, num_processes, time_quantum);

    printf("|\n\nTurnaround Time and Waiting Time:\n");
    float total_turnaround_time = 0;
    float total_waiting_time = 0;

    for (int i = 0; i < num_processes; i++) {
        printf("Process P%d:\tTurnaround Time: %d\tWaiting Time: %d\n", i + 1, processes[i].turnaround_time, processes[i].waiting_time);
        total_turnaround_time += processes[i].turnaround_time;
        total_waiting_time += processes[i].waiting_time;
    }

    float avg_turnaround_time = total_turnaround_time / num_processes;
    float avg_waiting_time = total_waiting_time / num_processes;

    printf("\nAverage Turnaround Time: %.2f\nAverage Waiting Time: %.2f\n", avg_turnaround_time, avg_waiting_time);

    return 0;
}



SLIP NO.14
/*Q.1 Write a C program to implement the shell which displays the command
prompt “myshell$”. It accepts the command, tokenize the command line and
execute it by creating the child process. Also implement the additional
command ‘typeline’ as
typeline +n filename
:- To print first n lines in the file.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_TOKENS 100

void execute_command(char *tokens[]) {
    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Child process
        execvp(tokens[0], tokens);
        perror("execvp");
        exit(EXIT_FAILURE);
    } else {
        // Parent process
        waitpid(pid, NULL, 0);
    }
}

void typeline_command(int n, char *filename) {
    FILE *file;
    char line[MAX_COMMAND_LENGTH];

    file = fopen(filename, "r");
    if (file == NULL) {
        perror("fopen");
        return;
    }

    for (int i = 0; i < n && fgets(line, sizeof(line), file) != NULL; i++) {
        printf("%s", line);
    }

    fclose(file);
}

int main() {
    char command[MAX_COMMAND_LENGTH];
    char *tokens[MAX_TOKENS];
    char *token;

    while (1) {
        printf("myshell$ ");
        fgets(command, sizeof(command), stdin);

        // Remove newline character
        command[strcspn(command, "\n")] = '\0';

        // Tokenize the command
        int token_count = 0;
        token = strtok(command, " ");

        while (token != NULL) {
            tokens[token_count++] = token;
            token = strtok(NULL, " ");
        }

        // Check if the 'typeline' command is used
        if (token_count >= 4 && strcmp(tokens[0], "typeline") == 0 && tokens[1][0] == '+') {
            int n = atoi(tokens[1] + 1);
            if (n > 0) {
                // 'typeline +n filename'
                typeline_command(n, tokens[2]);
            } else {
                printf("Invalid line count.\n");
            }
        } else {
            // Execute the command
            tokens[token_count] = NULL; // Null-terminate the array
            execute_command(tokens);
        }
    }

    return 0;
}



/*Q.2) Write a C program to simulate Non-preemptive Shortest Job First (SJF) –
scheduling. The arrival time and first CPU-burst of different jobs should be
input to the system. Accept no. of Processes, arrival time and burst time. The
output should give Gantt chart, turnaround time and waiting time for each
process. Also find the average waiting time and turnaround time.

*/


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



SLIP NO.15
/*Q.1 Write a C program to implement the shell. It should display the command
prompt “myshell$”. Tokenize the command line and execute the given
command by creating the child process. Additionally it should interpret the
following ‘list’ commands as
myshell$ list f dirname
:- To print names of all the files in current directory.*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_TOKENS 100

void execute_command(char *tokens[]) {
    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Child process
        execvp(tokens[0], tokens);
        perror("execvp");
        exit(EXIT_FAILURE);
    } else {
        // Parent process
        waitpid(pid, NULL, 0);
    }
}

void list_files(char *dirname) {
    DIR *dir;
    struct dirent *entry;

    dir = opendir(dirname);

    if (dir == NULL) {
        perror("opendir");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }

    closedir(dir);
}

int main() {
    char command[MAX_COMMAND_LENGTH];
    char *tokens[MAX_TOKENS];
    char *token;

    while (1) {
        printf("myshell$ ");
        fgets(command, sizeof(command), stdin);

        // Remove newline character
        command[strcspn(command, "\n")] = '\0';

        // Tokenize the command
        int token_count = 0;
        token = strtok(command, " ");

        while (token != NULL) {
            tokens[token_count++] = token;
            token = strtok(NULL, " ");
        }

        // Check if the 'list' command is used
        if (token_count >= 3 && strcmp(tokens[0], "list") == 0 && strcmp(tokens[1], "f") == 0) {
            // 'list f dirname'
            list_files(tokens[2]);
        } else {
            // Execute the command
            tokens[token_count] = NULL; // Null-terminate the array
            execute_command(tokens);
        }
    }

    return 0;
}



/*Q.2 Write the program to simulate preemptive Shortest Job First (SJF) –
scheduling. The arrival time and first CPU-burst of different jobs should be
input to the system. Accept no. of Processes, arrival time and burst time. The
output should give Gantt chart, turnaround time and waiting time for each
process. Also find the average waiting time and turnaround time*/

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


SLIP NO.16
/*Q.2 Write the program to simulate Non preemptive priority scheduling. The
arrival time and first CPU-burst of different jobs should be input to the
system. Accept no. of Processes, arrival time and burst time. The output
should give Gantt chart, turnaround time and waiting time for each process.
Also find the average waiting time and turnaround time.*/


#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 10

typedef struct {
    int process_id;
    int arrival_time;
    int burst_time;
    int priority;
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

void sort_by_priority(Process processes[], int num_processes) {
    for (int i = 0; i < num_processes - 1; i++) {
        for (int j = 0; j < num_processes - i - 1; j++) {
            if (processes[j].priority > processes[j + 1].priority) {
                swap(&processes[j], &processes[j + 1]);
            }
        }
    }
}

void priority_scheduling(Process processes[], int num_processes) {
    int time = 0;

    for (int i = 0; i < num_processes; i++) {
        if (processes[i].arrival_time > time) {
            time = processes[i].arrival_time;
        }

        processes[i].waiting_time = time - processes[i].arrival_time;
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;

        time += processes[i].burst_time;
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

        printf("Enter priority for process P%d: ", processes[i].process_id);
        scanf("%d", &processes[i].priority);
    }

    sort_by_arrival_time(processes, num_processes);
    priority_scheduling(processes, num_processes);
    print_gantt_chart(processes, num_processes);
    print_results(processes, num_processes);

    return 0;
}



SLIP NO.17
/*Q.1 Write the simulation program for demand paging and show the page
scheduling and total number of page faults according the Optimal page
replacement algorithm. Assume the memory of n frames.
Reference String
: 7, 5, 4, 8, 5, 7, 2, 3, 1, 3, 5, 9, 4, 6,*/


#include <stdio.h>
#include <stdlib.h>

#define MAX_FRAMES 10

typedef struct {
    int page;
    int last_used; // Index of the last occurrence of the page in the reference string
    int in_memory;
} PageEntry;

void initialize_memory(PageEntry memory[], int num_frames) {
    for (int i = 0; i < num_frames; i++) {
        memory[i].page = -1;
        memory[i].last_used = -1;
        memory[i].in_memory = 0;
    }
}

void print_memory(PageEntry memory[], int num_frames) {
    printf("Memory: ");
    for (int i = 0; i < num_frames; i++) {
        if (memory[i].page != -1) {
            printf("%d ", memory[i].page);
        } else {
            printf("- ");
        }
    }
    printf("\n");
}

int is_page_in_memory(PageEntry memory[], int num_frames, int page) {
    for (int i = 0; i < num_frames; i++) {
        if (memory[i].page == page) {
            return 1;
        }
    }
    return 0;
}

void page_fault(PageEntry memory[], int num_frames, int reference_string[], int reference_length, int *faults, int position) {
    int farthest = -1;
    int replace_index = -1;

    for (int i = 0; i < num_frames; i++) {
        int j;
        for (j = position + 1; j < reference_length; j++) {
            if (memory[i].page == reference_string[j]) {
                if (j > farthest) {
                    farthest = j;
                    replace_index = i;
                }
                break;
            }
        }

        if (j == reference_length) {
            replace_index = i;
            break;
        }
    }

    if (replace_index == -1) {
        replace_index = 0;
    }

    memory[replace_index].page = reference_string[position];
    memory[replace_index].last_used = position;
    memory[replace_index].in_memory = 1;
    *faults += 1;
}

void simulate_optimal(int reference_string[], int length, int num_frames) {
    PageEntry memory[MAX_FRAMES];
    int faults = 0;

    initialize_memory(memory, num_frames);

    printf("Simulation with Optimal Page Replacement Algorithm:\n");
    printf("Reference String: ");
    for (int i = 0; i < length; i++) {
        printf("%d ", reference_string[i]);
    }
    printf("\nNumber of Frames: %d\n", num_frames);

    for (int i = 0; i < length; i++) {
        int page = reference_string[i];

        if (!is_page_in_memory(memory, num_frames, page)) {
            page_fault(memory, num_frames, reference_string, length, &faults, i);
        }

        printf("Accessing Page %d\n", page);
        print_memory(memory, num_frames);
    }

    printf("\nTotal Number of Page Faults: %d\n", faults);
}

int main() {
    int reference_string[] = {7, 5, 4, 8, 5, 7, 2, 3, 1, 3, 5, 9, 4, 6};
    int length = sizeof(reference_string) / sizeof(reference_string[0]);
    int num_frames = 3;

    simulate_optimal(reference_string, length, num_frames);

    return 0;
}



/*
Q.2 Write the program to simulate FCFS CPU-scheduling. The arrival time and
first CPU-burst of different jobs should be input to the system. Accept no. of
Processes, arrival time and burst time. The output should give Gantt chart,
turnaround time and waiting time for each process. Also find the average
waiting time and turnaround time.*/

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

void calculate_turnaround_time(Process processes[], int num_processes) {
    processes[0].turnaround_time = processes[0].burst_time;
    processes[0].waiting_time = 0;

    for (int i = 1; i < num_processes; i++) {
        processes[i].waiting_time = processes[i - 1].waiting_time + processes[i - 1].burst_time;
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
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

    calculate_turnaround_time(processes, num_processes);
    print_gantt_chart(processes, num_processes);
    print_results(processes, num_processes);

    return 0;
}


/*SLIP NO.18
Q.1 Write the simulation program for demand paging and show the page
scheduling and total number of page faults according the LRU page
replacement algorithm. Assume the memory of n frames.
Reference String
: 3, 4, 5, 6, 3, 4, 7, 3, 4, 5, 6, 7, 2, 4, 6*/

#include <stdio.h>
#include <stdlib.h>

// Function to find the index of the least recently used page in frames
int findLRUPageIndex(int *lastUsed, int n) {
    int minIndex = 0;
    for (int i = 1; i < n; i++) {
        if (lastUsed[i] < lastUsed[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex;
}

// Function to simulate demand paging with LRU page replacement algorithm
void simulateDemandPagingLRU(int *referenceString, int referenceStringLength, int n) {
    int frames[n];
    int lastUsed[n]; // To keep track of the last used time for each page in frames
    int pageFaults = 0;

    // Initialize frames and lastUsed times
    for (int i = 0; i < n; i++) {
        frames[i] = -1; // -1 indicates an empty frame
        lastUsed[i] = 0;
    }

    // Simulate demand paging
    for (int i = 0; i < referenceStringLength; i++) {
        int page = referenceString[i];

        // Check if the page is present in frames
        int pagePresent = 0;
        for (int j = 0; j < n; j++) {
            if (frames[j] == page) {
                pagePresent = 1;
                lastUsed[j] = i + 1; // Update the last used time for the accessed page
                break;
            }
        }

        // If the page is not present in frames, handle page fault
        if (!pagePresent) {
            // Page fault, replace the least recently used page in frames
            int lruIndex = findLRUPageIndex(lastUsed, n);
            frames[lruIndex] = page;
            lastUsed[lruIndex] = i + 1; // Update the last used time for the newly loaded page
            pageFaults++;
        }

        // Print the current page scheduling order
        printf("%d ", page);
    }

    printf("\nTotal Page Faults: %d\n", pageFaults);
}

int main() {
    // Reference String: 3, 4, 5, 6, 3, 4, 7, 3, 4, 5, 6, 7, 2, 4, 6
    int referenceString[] = {3, 4, 5, 6, 3, 4, 7, 3, 4, 5, 6, 7, 2, 4, 6};
    int referenceStringLength = sizeof(referenceString) / sizeof(referenceString[0]);

    // Number of frames in memory
    int n = 3;

    // Simulate demand paging with LRU page replacement algorithm
    simulateDemandPagingLRU(referenceString, referenceStringLength, n);

    return 0;
}


/*Q.2 Write a C program to simulate FCFS CPU-scheduling. The arrival time and
first CPU-burst of different jobs should be input to the system. Accept no. of
Processes, arrival time and burst time. The output should give Gantt chart,
turnaround time and waiting time for each process. Also find the average
waiting time and turnaround time.*/


#include <stdio.h>

// Function to calculate turnaround time and waiting time
void calculateTurnaroundTimeAndWaitingTime(int processes[], int n, int burstTime[], int waitingTime[], int turnaroundTime[]) {
    // Turnaround time for the first process is its burst time
    turnaroundTime[0] = burstTime[0];

    // Waiting time for the first process is 0
    waitingTime[0] = 0;

    // Calculate turnaround time and waiting time for each process
    for (int i = 1; i < n; i++) {
        turnaroundTime[i] = turnaroundTime[i - 1] + burstTime[i];
        waitingTime[i] = turnaroundTime[i - 1];
    }
}

// Function to display Gantt chart
void displayGanttChart(int processes[], int n, int burstTime[], int turnaroundTime[]) {
    printf("\nGantt Chart:\n");

    // Display process numbers
    for (int i = 0; i < n; i++) {
        printf("| P%d ", processes[i]);
    }

    printf("|\n");

    // Display turnaround time
    printf("0");

    for (int i = 0; i < n; i++) {
        printf("      %d", turnaroundTime[i]);
    }

    printf("\n");
}

// Function to calculate and display average turnaround time and waiting time
void displayAverageTimes(int turnaroundTime[], int waitingTime[], int n) {
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

    // Sort processes based on arrival time (if not already sorted)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arrivalTime[j] > arrivalTime[j + 1]) {
                // Swap arrival times
                int tempArrival = arrivalTime[j];
                arrivalTime[j] = arrivalTime[j + 1];
                arrivalTime[j + 1] = tempArrival;

                // Swap burst times
                int tempBurst = burstTime[j];
                burstTime[j] = burstTime[j + 1];
                burstTime[j + 1] = tempBurst;

                // Swap process numbers
                int tempProcess = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = tempProcess;
            }
        }
    }

    // Calculate turnaround time and waiting time
    calculateTurnaroundTimeAndWaitingTime(processes, n, burstTime, waitingTime, turnaroundTime);

    // Display Gantt chart
    displayGanttChart(processes, n, burstTime, turnaroundTime);

    // Display turnaround time and waiting time for each process
    printf("\nProcess\tTurnaround Time\tWaiting Time\n");

    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\n", processes[i], turnaroundTime[i], waitingTime[i]);
    }

    // Display average turnaround time and waiting time
    displayAverageTimes(turnaroundTime, waitingTime, n);

    return 0;
}


/*SLIP NO.19
Q.2 Write the simulation program for Round Robin scheduling for given time
quantum. The arrival time and first CPU-burst of different jobs should be input
to the system. Accept no. of Processes, arrival time and burst time. The output
should give the Gantt chart, turnaround time and waiting time for each
process. Also display the average turnaround time and average waiting time.*/

#include <stdio.h>

// Function to simulate Round Robin scheduling
void simulateRoundRobin(int processes[], int n, int arrivalTime[], int burstTime[], int timeQuantum) {
    int remainingBurstTime[n];
    int turnaroundTime[n];
    int waitingTime[n];

    // Copy burst times to remaining burst times
    for (int i = 0; i < n; i++) {
        remainingBurstTime[i] = burstTime[i];
    }

    int currentTime = 0; // Current time during simulation
    int queue[n]; // Queue to store process indices
    int front = -1, rear = -1; // Front and rear pointers for the queue

    int timeQuantumRemaining = timeQuantum; // Remaining time quantum for the current process

    while (1) {
        // Check if all processes are done
        int allDone = 1;
        for (int i = 0; i < n; i++) {
            if (remainingBurstTime[i] > 0) {
                allDone = 0;
                break;
            }
        }

        if (allDone) {
            break;
        }

        // Enqueue processes that have arrived and have remaining burst time
        for (int i = 0; i < n; i++) {
            if (arrivalTime[i] <= currentTime && remainingBurstTime[i] > 0) {
                if (front == -1) {
                    front = 0;
                }

                rear = (rear + 1) % n;
                queue[rear] = i;
            }
        }

        // Dequeue the next process to execute
        int currentProcess = -1;
        if (front != -1) {
            currentProcess = queue[front];
            front = (front + 1) % n;
        }

        if (currentProcess == -1) {
            // If the queue is empty, there are processes yet to arrive
            currentTime++;
        } else {
            // Execute the current process for the time quantum or remaining burst time, whichever is smaller
            int executionTime = (remainingBurstTime[currentProcess] < timeQuantum) ? remainingBurstTime[currentProcess] : timeQuantum;
            remainingBurstTime[currentProcess] -= executionTime;
            currentTime += executionTime;

            // Update turnaround and waiting time for the current process
            turnaroundTime[currentProcess] = currentTime - arrivalTime[currentProcess];
            waitingTime[currentProcess] = turnaroundTime[currentProcess] - burstTime[currentProcess];

            // Enqueue the current process again if it still has remaining burst time
            if (remainingBurstTime[currentProcess] > 0) {
                rear = (rear + 1) % n;
                queue[rear] = currentProcess;
            }
        }
    }

    // Display Gantt chart
    printf("\nGantt Chart:\n");

    for (int i = 0; i < n; i++) {
        printf("| P%d ", processes[i]);
    }

    printf("|\n");

    // Display turnaround time and waiting time for each process
    printf("\nProcess\tTurnaround Time\tWaiting Time\n");

    float totalTurnaroundTime = 0, totalWaitingTime = 0;
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\n", processes[i], turnaroundTime[i], waitingTime[i]);
        totalTurnaroundTime += turnaroundTime[i];
        totalWaitingTime += waitingTime[i];
    }

    // Display average turnaround time and average waiting time
    printf("\nAverage Turnaround Time: %.2f", totalTurnaroundTime / n);
    printf("\nAverage Waiting Time: %.2f\n", totalWaitingTime / n);
}

int main() {
    int n, timeQuantum;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int processes[n];
    int arrivalTime[n];
    int burstTime[n];

    printf("Enter the arrival time and burst time for each process:\n");

    for (int i = 0; i < n; i++) {
        printf("Process %d:\n", i + 1);
        processes[i] = i + 1;

        printf("Arrival Time: ");
        scanf("%d", &arrivalTime[i]);

        printf("Burst Time: ");
        scanf("%d", &burstTime[i]);
    }

    printf("Enter the time quantum: ");
    scanf("%d", &timeQuantum);

    // Simulate Round Robin scheduling
    simulateRoundRobin(processes, n, arrivalTime, burstTime, timeQuantum);

    return 0;
}


/*SLIP NO.20
.1 Write a C program to implement the shell which displays the command
prompt “myshell$”. It accepts the command, tokenize the command line and
execute it by creating the child process. Also implement the additional
command ‘typeline’ as
typeline -a
filename
:- To print all lines in the file.*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_TOKENS 100

// Function to tokenize the input command
void tokenizeCommand(char *command, char *tokens[]) {
    int i = 0;
    tokens[i] = strtok(command, " \t\n");

    while (tokens[i] != NULL && i < MAX_TOKENS - 1) {
        i++;
        tokens[i] = strtok(NULL, " \t\n");
    }

    tokens[i] = NULL;
}

// Function to execute the command
void executeCommand(char *tokens[]) {
    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
    } else if (pid == 0) {
        // Child process
        if (execvp(tokens[0], tokens) == -1) {
            perror("execvp");
            exit(EXIT_FAILURE);
        }
    } else {
        // Parent process
        int status;
        waitpid(pid, &status, 0);

        if (WIFEXITED(status)) {
            printf("Child process exited with status %d\n", WEXITSTATUS(status));
        } else {
            printf("Child process did not exit normally\n");
        }
    }
}

// Function to implement the 'typeline' command
void typelineCommand(char *filename) {
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        perror("fopen");
        return;
    }

    char line[MAX_COMMAND_LENGTH];
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
    }

    fclose(file);
}

int main() {
    char command[MAX_COMMAND_LENGTH];
    char *tokens[MAX_TOKENS];

    while (1) {
        // Display command prompt
        printf("myshell$ ");
        fflush(stdout);

        // Read user input
        if (fgets(command, sizeof(command), stdin) == NULL) {
            break;
        }

        // Remove the newline character from the end of the command
        command[strcspn(command, "\n")] = '\0';

        // Tokenize the command
        tokenizeCommand(command, tokens);

        // Check for the 'typeline' command
        if (tokens[0] != NULL && strcmp(tokens[0], "typeline") == 0) {
            if (tokens[1] != NULL) {
                typelineCommand(tokens[1]);
            } else {
                printf("Usage: typeline filename\n");
            }
        } else if (tokens[0] != NULL) {
            // Execute the command
            executeCommand(tokens);
        }
    }

    return 0;
}



/*Q.2 Write the program to simulate Non-preemptive Shortest Job First (SJF) –
scheduling. The arrival time and first CPU-burst of different jobs should be
input to the system. Accept no. of Processes, arrival time and burst time. The
output should give Gantt chart, turnaround time and waiting time for each
process. Also find the average waiting time and turnaround time.*/



#include <stdio.h>

// Function to calculate turnaround time and waiting time
void calculateTurnaroundTimeAndWaitingTime(int processes[], int n, int burstTime[], int waitingTime[], int turnaroundTime[]) {
    turnaroundTime[0] = burstTime[0];
    waitingTime[0] = 0;

    for (int i = 1; i < n; i++) {
        turnaroundTime[i] = turnaroundTime[i - 1] + burstTime[i];
        waitingTime[i] = turnaroundTime[i - 1];
    }
}

// Function to perform SJF scheduling
void performSJFScheduling(int processes[], int n, int arrivalTime[], int burstTime[]) {
    int remainingBurstTime[n];
    int turnaroundTime[n];
    int waitingTime[n];

    // Copy burst times to remaining burst times
    for (int i = 0; i < n; i++) {
        remainingBurstTime[i] = burstTime[i];
    }

    int currentTime = 0; // Current time during simulation
    int executedProcesses = 0; // Number of processes executed

    while (executedProcesses < n) {
        int shortestJob = -1;
        int shortestBurstTime = 9999;

        // Find the shortest job that has arrived
        for (int i = 0; i < n; i++) {
            if (arrivalTime[i] <= currentTime && remainingBurstTime[i] < shortestBurstTime && remainingBurstTime[i] > 0) {
                shortestJob = i;
                shortestBurstTime = remainingBurstTime[i];
            }
        }

        // If no job is found, increment the current time
        if (shortestJob == -1) {
            currentTime++;
        } else {
            // Execute the shortest job
            remainingBurstTime[shortestJob]--;
            currentTime++;

            // If the job is completed, calculate turnaround time and waiting time
            if (remainingBurstTime[shortestJob] == 0) {
                turnaroundTime[shortestJob] = currentTime - arrivalTime[shortestJob];
                waitingTime[shortestJob] = turnaroundTime[shortestJob] - burstTime[shortestJob];
                executedProcesses++;
            }
        }
    }

    // Display Gantt chart
    printf("\nGantt Chart:\n");

    for (int i = 0; i < n; i++) {
        printf("| P%d ", processes[i]);
    }

    printf("|\n");

    // Display turnaround time and waiting time for each process
    printf("\nProcess\tTurnaround Time\tWaiting Time\n");

    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\n", processes[i], turnaroundTime[i], waitingTime[i]);
    }

    // Calculate and display average turnaround time and average waiting time
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

    printf("Enter the arrival time and burst time for each process:\n");

    for (int i = 0; i < n; i++) {
        printf("Process %d:\n", i + 1);
        processes[i] = i + 1;

        printf("Arrival Time: ");
        scanf("%d", &arrivalTime[i]);

        printf("Burst Time: ");
        scanf("%d", &burstTime[i]);
    }

    // Perform SJF scheduling
    performSJFScheduling(processes, n, arrivalTime, burstTime);

    return 0;
}


20 slips completed                                                                                                         By- Prafull Chavan

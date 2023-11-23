/*SLIP NO.03
Q.1 Write the simulation program to implement demand paging and show the page
scheduling and total number of page faults according to the LRU (using
counter method) page replacement algorithm. Assume the memory of n
frames.
Reference String : 3,5,7,2,5,1,2,3,1,3,5,3,1,6,2*/

#include <stdio.h>
#include <stdlib.h>

// Function to find the index of the least recently used page in frames
int findLRUPageIndex(int *counter, int n) 
{
    int minIndex = 0;
    for (int i = 1; i < n; i++) {
        if (counter[i] < counter[minIndex]) 
        {
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


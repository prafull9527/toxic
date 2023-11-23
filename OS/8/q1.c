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


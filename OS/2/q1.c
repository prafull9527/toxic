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



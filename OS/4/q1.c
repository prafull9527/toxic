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
    for (int i = 0; i < n; i++) 
    {
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


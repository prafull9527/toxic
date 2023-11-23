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


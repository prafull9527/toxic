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


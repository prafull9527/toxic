
#include <stdio.h>
#include <stdlib.h>


int findLRUPageIndex(int *lastUsed, int n) {
    int minIndex = 0;
    for (int i = 1; i < n; i++) {
        if (lastUsed[i] < lastUsed[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex;
}


void simulateDemandPagingLRU(int *referenceString, int referenceStringLength, int n) {
    int frames[n];
    int lastUsed[n]; 
    int pageFaults = 0;

   
    for (int i = 0; i < n; i++) {
        frames[i] = -1; 
        lastUsed[i] = 0;
    }

  
    for (int i = 0; i < referenceStringLength; i++) {
        int page = referenceString[i];

     
        int pagePresent = 0;
        for (int j = 0; j < n; j++) {
            if (frames[j] == page) {
                pagePresent = 1;
                lastUsed[j] = i + 1;
                break;
            }
        }

     
        if (!pagePresent) {
          
            int lruIndex = findLRUPageIndex(lastUsed, n);
            frames[lruIndex] = page;
            lastUsed[lruIndex] = i + 1;
            pageFaults++;
        }

     
        printf("%d ", page);
    }

    printf("\nTotal Page Faults: %d\n", pageFaults);
}

int main() {
   
    int referenceString[] = {3, 4, 5, 6, 3, 4, 7, 3, 4, 5, 6, 7, 2, 4, 6};
    int referenceStringLength = sizeof(referenceString) / sizeof(referenceString[0]);

    
    int n = 3;

   
    simulateDemandPagingLRU(referenceString, referenceStringLength, n);

    return 0;
}


/*
#include <stdio.h>

#define MAX_FRAMES 10

void initializeFrames(int frames[], int n) {
    for (int i = 0; i < n; i++) {
        frames[i] = -1; // Initialize frames to -1 indicating empty frame
    }
}

void displayFrames(int frames[], int n) {
    for (int i = 0; i < n; i++) {
        if (frames[i] != -1) {
            printf("%d ", frames[i]);
        } else {
            printf("- ");
        }
    }
    printf("\n");
}

int findLRU(int frames[], int n, int indexes[]) {
    int min = indexes[0];
    int lruIndex = 0;

    for (int i = 1; i < n; i++) {
        if (indexes[i] < min) {
            min = indexes[i];
            lruIndex = i;
        }
    }

    return lruIndex;
}

int isInFrames(int frames[], int n, int page) {
    for (int i = 0; i < n; i++) {
        if (frames[i] == page) {
            return 1; // Page is present in frames
        }
    }
    return 0; // Page is not present in frames
}

void pageReplacementLRU(int referenceString[], int length, int frames[], int n) {
    int pageFaults = 0;
    int indexes[MAX_FRAMES]; // To store index of the last use of each frame

    initializeFrames(frames, n);

    for (int i = 0; i < length; i++) {
        printf("Reference String %d: ", referenceString[i]);
        displayFrames(frames, n);

        if (!isInFrames(frames, n, referenceString[i])) {
            // Page fault occurs
            pageFaults++;
            int lruIndex = findLRU(frames, n, indexes);
            frames[lruIndex] = referenceString[i];
        }

        // Update the index of the last use of the current page
        for (int j = 0; j < n; j++) {
            if (frames[j] != -1) {
                indexes[j]++;
            }
        }

        indexes[findLRU(frames, n, indexes)] = 0; // Reset the index of the last use for the newly added page
    }

    printf("\nTotal Page Faults: %d\n", pageFaults);
}

int main() {
    int referenceString[] = {3, 4, 5, 6, 3, 4, 7, 3, 4, 5, 6, 7, 2, 4, 6};
    int frames[MAX_FRAMES];
    int n;

    printf("Enter the number of frames: ");
    scanf("%d", &n);

    if (n > MAX_FRAMES || n <= 0) {
        printf("Invalid number of frames. Exiting...\n");
        return 1;
    }

    pageReplacementLRU(referenceString, sizeof(referenceString) / sizeof(referenceString[0]), frames, n);

    return 0;
}
*/

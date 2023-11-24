
#include <stdio.h>
#include <stdlib.h>


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


void simulateDemandPagingLRU(int *referenceString, int referenceStringLength, int n) {
    int frames[n];
    int counter[n];
    int pageFaults = 0;

    
    for (int i = 0; i < n; i++) {
        frames[i] = -1; 
        counter[i] = 0;
    }

    
    for (int i = 0; i < referenceStringLength; i++) {
        int page = referenceString[i];

      
        int pagePresent = 0;
        for (int j = 0; j < n; j++) {
            if (frames[j] == page) {
                pagePresent = 1;
                counter[j]++;
            } else {
                counter[j] >>= 1; 
            }
        }

       
        if (!pagePresent) {
            
            int lruIndex = findLRUPageIndex(counter, n);
            frames[lruIndex] = page;
            counter[lruIndex] = 1; 
            pageFaults++;
        }

      
        printf("%d ", page);
    }

    printf("\nTotal Page Faults: %d\n", pageFaults);
}

int main() {
    
    int referenceString[] = {3, 5, 7, 2, 5, 1, 2, 3, 1, 3, 5, 3, 1, 6, 2};
    int referenceStringLength = sizeof(referenceString) / sizeof(referenceString[0]);

  
    int n = 3;

 
    simulateDemandPagingLRU(referenceString, referenceStringLength, n);

    return 0;
}


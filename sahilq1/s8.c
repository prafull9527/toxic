//s8 q1
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
int referenceString[] = {8, 5, 7, 8, 5, 7, 2, 3, 7, 3, 5, 9, 4, 6, 2};
int referenceStringLength = sizeof(referenceString) / sizeof(referenceString[0]);
int n = 3;
simulateDemandPagingLRU(referenceString, referenceStringLength, n);
return 0;
}

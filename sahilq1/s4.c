//s4 q1
#include <stdio.h>
#include <stdlib.h>
int findMFUPageIndex(int *counter, int n) {
int maxIndex = 0;
for (int i = 1; i < n; i++) {
if (counter[i] > counter[maxIndex]) {
maxIndex = i;
}
}
return maxIndex;
}
void simulateDemandPagingMFU(int *referenceString, int referenceStringLength, int n) {
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
}
}
if (!pagePresent) {
int mfuIndex = findMFUPageIndex(counter, n);
frames[mfuIndex] = page;
counter[mfuIndex] = 1;
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
simulateDemandPagingMFU(referenceString, referenceStringLength, n);
return 0;
}

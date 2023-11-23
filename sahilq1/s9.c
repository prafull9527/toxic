#include <stdlib.h>
void simulateDemandPagingFIFO(int *referenceString, int referenceStringLength, int n) {
int frames[n];
int frameIndex = 0; 
int pageFaults = 0;
for (int i = 0; i < n; i++) {
frames[i] = -1; 
for (int i = 0; i < referenceStringLength; i++) {
int page = referenceString[i];
int pagePresent = 0;
for (int j = 0; j < n; j++) {
if (frames[j] == page) {
pagePresent = 1;
break;
}
}
if (!pagePresent) {
frames[frameIndex] = page;
frameIndex = (frameIndex + 1) % n; 
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
simulateDemandPagingFIFO(referenceString, referenceStringLength, n);
return 0;
}
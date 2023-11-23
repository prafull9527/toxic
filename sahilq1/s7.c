//s1q1
#include <stdio.h>
#include <stdlib.h>
int findOptimalPageIndex(int *pages, int n, int *referenceString, int
referenceStringLength, int currentPosition) {
int farthestIndex = -1;
int farthestDistance = -1;
for (int i = 0; i < n; i++) {
int nextPage = pages[i];
int nextOccurrence = -1;
for (int j = currentPosition + 1; j < referenceStringLength; j++) {
if (referenceString[j] == nextPage) {
nextOccurrence = j;
break;
}
}
if (nextOccurrence == -1) {
return i;
}
if (nextOccurrence > farthestDistance) {
farthestDistance = nextOccurrence;
farthestIndex = i;
}
}
return farthestIndex;
}
void simulateDemandPagingOptimal(int *referenceString, int referenceStringLength, int n) {
int frames[n];
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
int pageToReplace = findOptimalPageIndex(frames, n, referenceString,
referenceStringLength, i);
frames[pageToReplace] = page;
pageFaults++;
}
printf("%d ", page);
}
printf("\nTotal Page Faults: %d\n", pageFaults);
}
int main() {
int referenceString[] = {7, 5, 4, 8, 5, 7, 2, 3, 1, 3, 5, 9, 4, 6, 2};
int referenceStringLength = sizeof(referenceString) / sizeof(referenceString[0]);
int n = 3;
simulateDemandPagingOptimal(referenceString, referenceStringLength, n);
return 0;
}
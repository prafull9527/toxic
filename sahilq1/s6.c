//s6 q1
#include <stdio.h>
#include <stdlib.h>
int findMRUPageIndex(int *usageCounter, int n) {
int maxIndex = 0;
for (int i = 1; i < n; i++) {
if (usageCounter[i] > usageCounter[maxIndex]) {
maxIndex = i;
}
}
return maxIndex;
}
void simulateDemandPagingMRU(int *referenceString, int referenceStringLength, int n) {
int frames[n];
int usageCounter[n];
int pageFaults = 0;
for (int i = 0; i < n; i++) {
frames[i] = -1; 
usageCounter[i] = 0;
}
for (int i = 0; i < referenceStringLength; i++) {
int page = referenceString[i];
int pagePresent = 0;
for (int j = 0; j < n; j++) {
if (frames[j] == page) {
pagePresent = 1;
usageCounter[j] = i; 
break;
}
}
if (!pagePresent) {
	int mruIndex = findMRUPageIndex(usageCounter, n);
	frames[mruIndex] = page;
	usageCounter[mruIndex] = i; 
	page
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
	simulateDemandPagingMRU(referenceString, referenceStringLength, n);
	return 0;
	}
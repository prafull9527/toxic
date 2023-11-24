#include<stdio.h>
#define MAX 20

int frames[MAX],ref[MAX],mem[MAX][MAX],faults,
	sp,m,n;

void accept()
{
	int i;

	printf("Enter no.of frames:");
	scanf("%d", &n);

	printf("Enter no.of references:");
	scanf("%d", &m);

	printf("Enter reference string:\n");
	for(i=0;i<m;i++)
	{
		printf("[%d]=",i);
		scanf("%d",&ref[i]);
	}
}

void disp()
{
	int i,j;

	for(i=0;i<m;i++)
		printf("%3d",ref[i]);

	printf("\n\n");

	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(mem[i][j])
				printf("%3d",mem[i][j]);
			else
				printf("   ");
		}
		printf("\n");
	}

	printf("Total Page Faults: %d\n",faults);
}

int search(int pno)
{
	int i;

	for(i=0;i<n;i++)
	{
		if(frames[i]==pno)
			return i;
	}

	return -1;
}

int get_opt(int s)
{
	int i,j,pos_i=-1,pos_j=-1;

	for(j=0;j<n;j++)
	{
		for(i=s;i<m;i++)
		{
			if(ref[i]==frames[j])
			{
				if(i > pos_i)
				{
					pos_i = i;
					pos_j = j;
				}
				break;
			}
		}

		if(i==m) return j;

	}

	return pos_j;
}


void opt()
{
	int i,j,k;

	for(i=0;i<m && sp<n;i++)
	{
		k=search(ref[i]);
		if(k==-1)
		{
			frames[sp]=ref[i];
			faults++;
			sp++;

			for(j=0;j<n;j++)
				mem[j][i]=frames[j];
		}
	}

	sp=0;
	for(;i<m;i++)
	{
		k = search(ref[i]);
		if(k==-1)
		{
			sp = get_opt(i);
			frames[sp] = ref[i];
			faults++;

			for(j=0;j<n;j++)
				mem[j][i] = frames[j];
		}
	}
}
						

int main()
{
	accept();
	opt();
	disp();

	return 0;
}


/*
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
*/

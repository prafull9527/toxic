#include<stdio.h>
#define MAX 20

int frames[MAX],ref[MAX],mem[MAX][MAX],faults,sp,m,n;

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

void fifo()
{
	int i,j;

	for(i=0;i<m;i++)
	{
		if(search(ref[i])==-1)
		{
			frames[sp] = ref[i];
			sp = (sp+1)%n;
			faults++;
			for(j=0;j<n;j++)
				mem[j][i] = frames[j];

		}
	}
}

int main()
{
	accept();
	fifo();
	disp();

	return 0;
}


/*
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
*/

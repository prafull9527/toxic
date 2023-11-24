#include <stdio.h>
#include <stdlib.h>


int isPagePresent(int page, int *frames, int n) {
    for (int i = 0; i < n; i++) {
        if (frames[i] == page) {
            return 1; 
        }
    }
    return 0; 
}


int findOldestPageIndex(int *arrival, int n) {
    int oldestIndex = 0;
    for (int i = 1; i < n; i++) {
        if (arrival[i] < arrival[oldestIndex]) {
            oldestIndex = i;
        }
    }
    return oldestIndex;
}


void simulateDemandPaging(int *referenceString, int referenceStringLength, int n) {
    int frames[n];
    int arrival[n]; 
    int pageFaults = 0;

   
    for (int i = 0; i < n; i++) {
        frames[i] = -1; 
        arrival[i] = 0;
    }

    
    for (int i = 0; i < referenceStringLength; i++) {
        int page = referenceString[i];

      
        if (!isPagePresent(page, frames, n)) {
          
            int oldestIndex = findOldestPageIndex(arrival, n);
            frames[oldestIndex] = page;
            arrival[oldestIndex] = i + 1; 
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

   
    simulateDemandPaging(referenceString, referenceStringLength, n);

    return 0;
}

/*

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
*/

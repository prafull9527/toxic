/*Q.2 Write the simulation program for demand paging and show the page
scheduling and total number of page faults according the Optimal page
replacement algorithm. Assume the memory of n frames.
Reference String
: 7, 5, 4, 8, 5, 7, 2, 3, 1, 3, 5, 9, 4, 6,*/


#include <stdio.h>
#include <stdlib.h>

void optimal_page_replacement(int pages[], int n, int frames);

int main() {
    int reference_string[] = {7, 5, 4, 8, 5, 7, 2, 3, 1, 3, 5, 9, 4, 6};
    int n = sizeof(reference_string) / sizeof(reference_string[0]);
    int frames;

    printf("Enter the number of frames: ");
    scanf("%d", &frames);

    optimal_page_replacement(reference_string, n, frames);

    return 0;
}

void optimal_page_replacement(int pages[], int n, int frames) {
    int page_faults = 0;
    int page_table[frames];
    int page_table_index = 0;

    for (int i = 0; i < frames; ++i) {
        page_table[i] = -1;
    }

    printf("\nPage Scheduling:\n");
    printf("-----------------\n");

    for (int i = 0; i < n; ++i) {
        int page = pages[i];
        int page_found = 0;

        // Check if the page is already in the page table
        for (int j = 0; j < frames; ++j) {
            if (page_table[j] == page) {
                page_found = 1;
                break;
            }
        }

        // If page not found, replace the page using Optimal page replacement algorithm
        if (!page_found) {
            // Find the page to be replaced
            int replace_page = -1;
            int farthest_distance = -1;

            for (int j = 0; j < frames; ++j) {
                int next_occurrence = -1;
                for (int k = i + 1; k < n; ++k) {
                    if (pages[k] == page_table[j]) {
                        next_occurrence = k;
                        break;
                    }
                }

                if (next_occurrence == -1) {
                    replace_page = j;
                    break;
                } else {
                    if (next_occurrence > farthest_distance) {
                        farthest_distance = next_occurrence;
                        replace_page = j;
                    }
                }
            }

            // Replace the page
            page_table[replace_page] = page;
            page_faults++;

            // Print the page scheduling
            printf("Page %d -> ", page);
            for (int j = 0; j < frames; ++j) {
                printf("%d ", page_table[j]);
            }
            printf("Page Fault\n");
        }
    }

    printf("\nTotal Number of Page Faults: %d\n", page_faults);
}


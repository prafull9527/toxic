/*SLIP NO.11
Q.1 Write the simulation program for demand paging and show the page
scheduling and total number of page faults according the LFU page
replacement algorithm. Assume the memory of n frames.
Reference String: 3, 4, 5, 6, 3, 4, 7, 3, 4, 5, 6, 7, 2, 4, 6
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_FRAMES 10

typedef struct {
    int page;
    int frequency;
} PageEntry;

typedef struct {
    PageEntry entries[MAX_FRAMES];
    int count;
} PageTable;

int find_page(PageTable *table, int page) {
    for (int i = 0; i < table->count; i++) {
        if (table->entries[i].page == page) {
            return i;
        }
    }
    return -1;
}

int find_lfu_page(PageTable *table) {
    int min_index = 0;
    for (int i = 1; i < table->count; i++) {
        if (table->entries[i].frequency < table->entries[min_index].frequency) {
            min_index = i;
        }
    }
    return min_index;
}

void print_memory(PageTable *table) {
    printf("Memory: ");
    for (int i = 0; i < table->count; i++) {
        printf("%d ", table->entries[i].page);
    }
    printf("\n");
}

void simulate(int reference_string[], int length, int num_frames) {
    PageTable table;
    table.count = 0;

    int page_faults = 0;

    for (int i = 0; i < length; i++) {
        int page = reference_string[i];

        int index = find_page(&table, page);

        if (index == -1) {
            // Page fault
            page_faults++;

            if (table.count < num_frames) {
                // There is space in memory
                table.entries[table.count].page = page;
                table.entries[table.count].frequency = 1;
                table.count++;
            } else {
                // LFU Page Replacement
                int lfu_index = find_lfu_page(&table);
                table.entries[lfu_index].page = page;
                table.entries[lfu_index].frequency = 1;
            }
        } else {
            // Page hit, increase frequency
            table.entries[index].frequency++;
        }

        printf("Accessing Page %d\n", page);
        print_memory(&table);
    }

    printf("\nTotal Number of Page Faults: %d\n", page_faults);
}

int main() {
    int reference_string[] = {3, 4, 5, 6, 3, 4, 7, 3, 4, 5, 6, 7, 2, 4, 6};
    int length = sizeof(reference_string) / sizeof(reference_string[0]);

    int num_frames = 3;

    simulate(reference_string, length, num_frames);

    return 0;
}


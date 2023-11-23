//s11 q1
#include <stdio.h>
#include <stdlib.h>
#define MAX_FRAMES 10
typedef struct {
int page;
int last_used;
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
int find_lru_page(PageTable *table) {
int min_index = 0;
for (int i = 1; i < table->count; i++) {
if (table->entries[i].last_used < table->entries[min_index].last_used) {
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
void update_last_used(PageTable *table, int index) {
table->entries[index].last_used = 0;
for (int i = 0; i < table->count; i++) {
if (i != index) {
table->entries[i].last_used++;
}
}
}
void simulate(int reference_string[], int length, int num_frames) {
PageTable table;
table.count = 0;
int page_faults = 0;
for (int i = 0; i < length; i++) {
int page = reference_string[i];
int index = find_page(&table, page);
if (index == -1) {
page_faults++;
if (table.count < num_frames) {
table.entries[table.count].page = page;
table.entries[table.count].last_used = 0;
table.count++;
} else {
int lru_index = find_lru_page(&table);
table.entries[lru_index].page = page;
update_last_used(&table, lru_index);
}
} else {
update_last_used(&table, index);
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
#include <stdio.h>
#include <stdlib.h>
#define MAX_FRAMES 10
typedef struct {
int page;
int in_memory;
} PageEntry;
void initialize_memory(PageEntry memory[], int num_frames) {
for (int i = 0; i < num_frames; i++) {
memory[i].page = -1;
memory[i].in_memory = 0;
}
}
void print_memory(PageEntry memory[], int num_frames) {
printf("Memory: ");
for (int i = 0; i < num_frames; i++) {
if (memory[i].page != -1) {
printf("%d ", memory[i].page);
} else {
printf("- ");
}
}
printf("\n");
}
int is_page_in_memory(PageEntry memory[], int num_frames, int page) {
for (int i = 0; i < num_frames; i++) {
if (memory[i].page == page) {
return 1;
}
}
return 0;
}
void page_fault(PageEntry memory[], int num_frames, int page, int *faults, int
*next_position) {
    if (*next_position == num_frames) {
*next_position = 0;
}
if (memory[*next_position].in_memory) {
*faults += 1;
}
memory[*next_position].page = page;
memory[*next_position].in_memory = 1;
*next_position += 1;
}
void simulate_fifo(int reference_string[], int length, int num_frames) {
PageEntry memory[MAX_FRAMES];
int faults = 0;
int next_position = 0;
initialize_memory(memory, num_frames);
printf("Simulation with FIFO Page Replacement Algorithm:\n");
printf("Reference String: ");
for (int i = 0; i < length; i++) {
printf("%d ", reference_string[i]);
}
printf("\nNumber of Frames: %d\n", num_frames);
for (int i = 0; i < length; i++) {
int page = reference_string[i];
if (!is_page_in_memory(memory, num_frames, page)) {
page_fault(memory, num_frames, page, &faults, &next_position);
}
printf("Accessing Page %d\n", page);
print_memory(memory, num_frames);
}
printf("\nTotal Number of Page Faults: %d\n", faults);
}
int main() {
int reference_string[] = {2, 4, 5, 6, 9, 4, 7, 3, 4, 5, 6, 7, 2, 4, 7, 1};
int length = sizeof(reference_string) / sizeof(reference_string[0]);
int num_frames = 3;
simulate_fifo(reference_string, length, num_frames);
return 0;
}
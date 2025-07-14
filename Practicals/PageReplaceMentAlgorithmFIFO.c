// FIFO (First In First Out) page replacement algorithm
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>
#define MAX_PAGES 3

int main() {
    int page_faults = 0;
    int page_hits = 0;  // Added to track page hits
    int page_table[MAX_PAGES];
    memset(page_table, -1, sizeof(page_table));

    printf("Enter the number of pages: ");
    int num_pages;
    scanf("%d", &num_pages);

    int page_sequence[num_pages];
    printf("Enter the page sequence: ");
    for (int i = 0; i < num_pages; i++) {
        scanf("%d", &page_sequence[i]);
    }

    printf("\nPage Sequence: ");
    for (int i = 0; i < num_pages; i++) {
        printf("%d ", page_sequence[i]);
    }
    printf("\n");

    printf("Initial Page Table: ");
    for (int i = 0; i < MAX_PAGES; i++) {
        printf("%d ", page_table[i]);
    }
    printf("\n\n");

    for (int i = 0; i < num_pages; i++) {
        int page = page_sequence[i];
        bool page_found = false;

        // Check if page is already in memory
        for (int j = 0; j < MAX_PAGES; j++) {
            if (page_table[j] == page) {
                page_found = true;
                break;
            }
        }

        if (!page_found) {
            page_faults++;
            // FIFO replacement - shift all pages left
            for (int j = 0; j < MAX_PAGES - 1; j++) {
                page_table[j] = page_table[j + 1];
            }
            // Add new page at the end
            page_table[MAX_PAGES - 1] = page;
            
            printf("Step %d: Page %d - FAULT\n", i+1, page);
        } else {
            page_hits++;  // Increment page hit counter
            printf("Step %d: Page %d - HIT\n", i+1, page);
        }
        
        // Display current page table after each step
        printf("Page Table: ");
        for (int j = 0; j < MAX_PAGES; j++) {
            if (page_table[j] == -1) {
                printf("[ ] ");  // Show empty frames clearly
            } else {
                printf("[%d] ", page_table[j]);
            }
        }
        printf("\n\n");
    }

    // Final statistics
    printf("\n===== Final Results =====\n");
    printf("Total Page Faults: %d\n", page_faults);
    printf("Total Page Hits: %d\n", page_hits);
    printf("Page Fault Rate: %.2f%%\n", (float)page_faults/num_pages*100);
    printf("Page Hit Rate: %.2f%%\n", (float)page_hits/num_pages*100);
    
    return 0;
}
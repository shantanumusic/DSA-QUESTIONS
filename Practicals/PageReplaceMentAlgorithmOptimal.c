#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_FRAMES 3

// Function to check if a page exists in frames
bool isPagePresent(int frames[], int page, int frame_count) {
    for (int i = 0; i < frame_count; i++) {
        if (frames[i] == page) {
            return true;
        }
    }
    return false;
}

// Function to find the page that won't be used for longest time in future
int findOptimalPage(int frames[], int frame_count, int pages[], int page_count, int current_index) {
    int farthest = -1, farthest_index = -1;

    for (int i = 0; i < frame_count; i++) {
        int j;
        for (j = current_index; j < page_count; j++) {
            if (frames[i] == pages[j]) {
                if (j > farthest) {
                    farthest = j;
                    farthest_index = i;
                }
                break;
            }
        }
        // If page is not found in future, it's the optimal to replace
        if (j == page_count) {
            return i;
        }
    }
    return (farthest_index == -1) ? 0 : farthest_index;
}

void optimalPageReplacement(int pages[], int page_count, int frame_count) {
    int frames[frame_count];
    int page_faults = 0;
    int page_hits = 0;

    // Initialize all frames as empty
    for (int i = 0; i < frame_count; i++) {
        frames[i] = -1;
    }

    printf("Page Reference String: ");
    for (int i = 0; i < page_count; i++) {
        printf("%d ", pages[i]);
    }
    printf("\n\n");

    for (int i = 0; i < page_count; i++) {
        printf("Step %d: Page %d | ", i+1, pages[i]);

        // If page is already present, it's a hit
        if (isPagePresent(frames, pages[i], frame_count)) {
            page_hits++;
            printf("Hit   | ");
        } else {
            page_faults++;
            printf("Fault | ");

            // Find the first empty frame
            bool frame_found = false;
            for (int j = 0; j < frame_count; j++) {
                if (frames[j] == -1) {
                    frames[j] = pages[i];
                    frame_found = true;
                    break;
                }
            }

            // If no empty frame, find optimal page to replace
            if (!frame_found) {
                int optimal_index = findOptimalPage(frames, frame_count, pages, page_count, i+1);
                frames[optimal_index] = pages[i];
            }
        }

        // Display current frames
        printf("Frames: ");
        for (int j = 0; j < frame_count; j++) {
            if (frames[j] == -1) {
                printf("[ ] ");
            } else {
                printf("[%d] ", frames[j]);
            }
        }
        printf("\n");
    }

    // Print final statistics
    printf("\n===== Final Results =====\n");
    printf("Total Page Faults: %d\n", page_faults);
    printf("Total Page Hits: %d\n", page_hits);
    printf("Page Fault Rate: %.2f%%\n", (float)page_faults/page_count*100);
    printf("Page Hit Rate: %.2f%%\n", (float)page_hits/page_count*100);
}

int main() {
    int page_count;
    printf("Enter number of pages in reference string: ");
    scanf("%d", &page_count);

    int pages[page_count];
    printf("Enter the page reference string (space separated): ");
    for (int i = 0; i < page_count; i++) {
        scanf("%d", &pages[i]);
    }

    int frame_count;
    printf("Enter number of frames (1-%d): ", MAX_FRAMES);
    scanf("%d", &frame_count);

    if (frame_count < 1 || frame_count > MAX_FRAMES) {
        printf("Invalid number of frames. Using default %d frames.\n", MAX_FRAMES);
        frame_count = MAX_FRAMES;
    }

    optimalPageReplacement(pages, page_count, frame_count);

    return 0;
 }
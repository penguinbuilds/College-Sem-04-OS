#include <stdio.h>

#define MAX_PAGES 100

int main() {
    int page_frames, num_pages, page_faults = 0;
    int pages[MAX_PAGES], frames[MAX_PAGES];

    printf("Enter the number of page frames: ");
    scanf("%d", &page_frames);

    printf("Enter the number of pages: ");
    scanf("%d", &num_pages);

    printf("Enter the reference string: ");
    for (int i = 0; i < num_pages; i++) {
        scanf("%d", &pages[i]);
    }

    for (int i = 0; i < page_frames; i++) {
        frames[i] = -1;
    }

    int pointer = 0;
    for (int i = 0; i < num_pages; i++) {
        int page = pages[i];
        int found = 0;

        for (int j = 0; j < page_frames; j++) {
            if (frames[j] == page) {
                found = 1;
                break;
            }
        }

        if (!found) {
            frames[pointer] = page;
            pointer = (pointer + 1) % page_frames;
            page_faults++;
        }

        printf("Frame state after page %d: ", page);
        for (int j = 0; j < page_frames; j++) {
            printf("%d ", frames[j]);
        }
        printf("\n");
    }

    int hit = num_pages - page_faults;

    printf("Total page faults: %d\n", page_faults);
    printf("Total page hits: %d\n", hit);

    return 0;
}

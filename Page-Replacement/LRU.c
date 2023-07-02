#include <stdio.h>

#define MAX_PAGES 100
#define MAX_FRAMES 10

int main() {
    int page_frames, num_pages, page_faults = 0, page_hits = 0;
    int pages[MAX_PAGES], frames[MAX_FRAMES], time[MAX_FRAMES];

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
        time[i] = 0;
    }

    int page_index = 0;
    for (int i = 0; i < num_pages; i++) {
        int page = pages[i];
        int found = 0;

        for (int j = 0; j < page_frames; j++) {
            if (frames[j] == page) {
                found = 1;
                time[j] = i;
                page_hits++;
                break;
            }
        }

        if (!found) {
            int lru_index = 0;
            int min_time = time[0];

            for (int j = 1; j < page_frames; j++) {
                if (time[j] < min_time) {
                    lru_index = j;
                    min_time = time[j];
                }
            }

            frames[lru_index] = page;
            time[lru_index] = i;
            page_faults++;
        }

        printf("Frame state after page %d: ", page);
        for (int j = 0; j < page_frames; j++) {
            printf("%d ", frames[j]);
        }
        printf("\n");
    }

    printf("Total page hits: %d\n", page_hits);
    printf("Total page faults: %d\n", page_faults);

    return 0;
}

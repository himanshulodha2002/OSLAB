#include <stdio.h>
#include <stdlib.h>

#define MAX_FRAMES 10

int main() {
    int reference_string[50], frames[MAX_FRAMES], n, num_frames, page_faults = 0, frame_index = 0;
    int recent_counter[MAX_FRAMES] = {0};

    // Input the number of pages
    printf("Enter the number of pages: ");
    scanf("%d", &n);

    // Input the reference string
    printf("Enter the reference string: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &reference_string[i]);

    // Input the number of frames
    printf("Enter the number of frames: ");
    scanf("%d", &num_frames);

    // Initialize frames array to -1 (indicating empty frame)
    for (int i = 0; i < num_frames; i++){
        frames[i] = -1;
        recent_counter[i] = -1;
    }
    // Iterate over the reference string
    for (int i = 0; i < n; i++) {
        int page_found = 0;

        // Check if page is already in frames
        for (int j = 0; j < num_frames; j++) {
            if (frames[j] == reference_string[i]) {
                page_found = 1;
                recent_counter[j] = i; // Update the recent_counter when page is found
                break;
            }
        }

        // If page is not in frames, replace a page with least recent access
        if (!page_found) {
            int lru_frame_index = 0;
            for (int j = 1; j < num_frames; j++) {
                if (recent_counter[j] < recent_counter[lru_frame_index])
                    lru_frame_index = j;
            }
            frames[lru_frame_index] = reference_string[i];
            recent_counter[lru_frame_index] = i;
            page_faults++;
        }

        // Print the frames
        for (int j = 0; j < num_frames; j++)
            printf("\t%d", frames[j]);
        printf("\n");
    }

    // Output the number of page faults
    printf("\nThe number of page faults is %d\n", page_faults);
    return 0;
}

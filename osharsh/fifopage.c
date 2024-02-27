// #include <stdio.h>
// int main()
// {
//     int incomingStream[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1};
//     int pageFaults = 0;
//     int frames = 3;
//     int m, n, s, pages;
//     pages = sizeof(incomingStream) / sizeof(incomingStream[0]);
//     printf(" Incoming \t Frame 1 \t Frame 2 \t Frame 3 ");
//     int temp[frames];
//     for (m = 0; m < frames; m++)
//     {
//         temp[m] = -1;
//     }
//     for (m = 0; m < pages; m++)
//     {
//         s = 0;
//         for (n = 0; n < frames; n++)
//         {
//             if (incomingStream[m] == temp[n])
//             {
//                 s++;
//                 pageFaults--;
//             }
//         }
//         pageFaults++;
//         if ((pageFaults <= frames) && (s == 0))
//         {
//             temp[m] = incomingStream[m];
//         }
//         else if (s == 0)
//         {
//             temp[(pageFaults - 1) % frames] = incomingStream[m];
//         }
//         printf("\n");
//         printf("%d\t\t\t", incomingStream[m]);
//         for (n = 0; n < frames; n++)
//         {
//             if (temp[n] != -1)
//                 printf(" %d\t\t\t", temp[n]);
//             else
//                 printf(" - \t\t\t");
//         }
//     }
//     printf("\nTotal Page Faults:\t%d\n", pageFaults);
//     return 0;
// }

#include <stdio.h>

#define MAX_FRAMES 10
#define MAX_PAGES 50

int main() {
    int reference_string[MAX_PAGES], frames[MAX_FRAMES];
    int n, num_frames, page_faults = 0, frame_index = 0;

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
    for (int i = 0; i < MAX_FRAMES; i++)
        frames[i] = -1;
    // Iterate over the reference string
    for (int i = 0; i < n; i++) {
        int page_found = 0;

        // Check if page is already in frames
        for (int j = 0; j < num_frames; j++) {
            if (frames[j] == reference_string[i]) {
                page_found = 1;
                break;
            }
        }

        // If page is not in frames, replace the oldest page
        if (!page_found) {
            frames[frame_index] = reference_string[i];
            frame_index = (frame_index + 1) % num_frames;
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

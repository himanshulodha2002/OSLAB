#include <stdio.h>

void worstFit(int blocksize[], int m, int processSize[], int n) {
    int allocation[n];
    for (int i = 0; i < n; i++) {
        allocation[i] = -1;
        int wstidx = -1;
        for (int j = 0; j < m; j++) {
            if (blocksize[j] >= processSize[i] && (wstidx == -1 || blocksize[wstidx] < blocksize[j])) {
                wstidx = j;
            }
        }
        if (wstidx != -1) {
            allocation[i] = wstidx;
            blocksize[wstidx] -= processSize[i];
        }
    }
    printf("Process No\tProcess Size\tBlock No.\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t", i + 1, processSize[i]);
        if (allocation[i] != -1)
            printf("%d", allocation[i] + 1);
        else
            printf("Not Allocated");
        printf("\n");
    }
}

int main() {
    int blocksize[] = {100, 500, 200, 300, 600};
    int processSize[] = {212, 417, 112, 426};
    int m = sizeof(blocksize) / sizeof(blocksize[0]);
    int n = sizeof(processSize) / sizeof(processSize[0]);

    worstFit(blocksize, m, processSize, n);
    return 0;
}

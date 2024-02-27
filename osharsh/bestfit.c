#include <stdio.h>

void bestFit(int bs[], int m, int ps[], int n) {
    int allocation[n];
    for (int i = 0; i < n; i++) {
        allocation[i] = -1;
        for (int j = 0; j < m; j++) {
            if (bs[j] >= ps[i] && (allocation[i] == -1 || bs[allocation[i]] > bs[j])) {
                allocation[i] = j;
            }
        }
        if (allocation[i] != -1) {
            bs[allocation[i]] -= ps[i];
        }
    }
    printf("\nProcess\tSize\tBlock\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t", i + 1, ps[i]);
        if (allocation[i] != -1)
            printf("%d", allocation[i] + 1);
        else
            printf("NA");
        printf("\n");
    }
}

int main() {
    int bs[] = {100, 50, 25, 430, 600};
    int ps[] = {20, 45, 100, 426};
    bestFit(bs, sizeof(bs) / sizeof(bs[0]), ps, sizeof(ps) / sizeof(ps[0]));
    return 0;
}

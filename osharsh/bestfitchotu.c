#include <stdio.h>
void bf(int bs[], int m, int ps[], int n)
{
    int allocation[n], i, j;
    for (i = 0; i < n; i++)
    {
        allocation[i] = -1;
    }
    for (i = 0; i < n; i++)
    {
        int bestidx = -1;
        for (j = 0; j < n; j++)
        {
            if (bs[j] >= ps[i] && (bestidx == -1 || bs[bestidx] > bs[j]))
            {
                bestidx = j;
            }
        }

        if (bestidx != -1)
        {
            allocation[i] = bestidx;
            bs[bestidx] -= ps[i];
        }
    }
    printf("\nprocess no.\tprocess size.\tblock no\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t\t", i + 1, ps[i]);
        printf("%d\n", allocation[i]);
    }
}
int main()
{
    int bs[] = {100, 50, 25, 430, 600};
    int ps[] = {20, 45, 100, 426};
    int m = sizeof(bs) / sizeof(bs[0]);
    int n = sizeof(ps) / sizeof(ps[0]);

    bf(bs, m, ps, n);
    return 0;
}

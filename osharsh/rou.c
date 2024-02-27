#include <stdio.h>

int main()
{
      int n, time_quantum;
      int at[10], bt[10], rt[10], wt[10], tat[10];
      float avg_wt = 0, avg_tat = 0;

      printf("Enter Total Number of Processes: ");
      scanf("%d", &n);

      printf("Enter Arrival Time and Burst Time for Each Process:\n");
      for (int i = 0; i < n; i++)
      {
            printf("Process %d:\n", i + 1);
            printf("Arrival Time: ");
            scanf("%d", &at[i]);
            printf("Burst Time: ");
            scanf("%d", &bt[i]);
            rt[i] = bt[i];
      }

      printf("Enter Time Quantum: ");
      scanf("%d", &time_quantum);

      int remain = n;
      int time = 0;

      printf("\nProcess\t| Turnaround Time | Waiting Time\n\n");
      while (remain > 0)
      {
            for (int i = 0; i < n; i++)
            {
                  if (rt[i] > 0)
                  {
                        if (rt[i] <= time_quantum)
                        {
                              time += rt[i];
                              rt[i] = 0;
                              tat[i] = time - at[i];
                              wt[i] = tat[i] - bt[i];
                              avg_wt += wt[i];
                              avg_tat += tat[i];
                              remain--;
                              printf("P%d\t|\t%d\t|\t%d\n", i + 1, tat[i], wt[i]);
                        }
                        else
                        {
                              time += time_quantum;
                              rt[i] -= time_quantum;
                        }
                  }
            }
      }

      avg_wt /= n;
      avg_tat /= n;
      printf("\nAverage Waiting Time: %.2f\n", avg_wt);
      printf("Average Turnaround Time: %.2f\n", avg_tat);

      return 0;
}

#include <stdio.h>
#define MAX_PROCESSES 10
#define MAX_RESOURCES 10

int main()
{
  int MAX[MAX_PROCESSES][MAX_RESOURCES], alloc[MAX_PROCESSES][MAX_RESOURCES], avail[MAX_RESOURCES];
  int p, r, i, j, process, count = 0;
  int completed[MAX_PROCESSES] = {0}; // Array to track completed processes, initialized to 0
  int safeSequence[MAX_PROCESSES] = {0};

  printf("Enter the number of processes: ");
  scanf("%d", &p);

  printf("Enter the number of resources: ");
  scanf("%d", &r);

  printf("\nEnter the max matrix for each process:\n");
  for (i = 0; i < p; i++)
  {
    printf("For process %d: ", i + 1);
    for (j = 0; j < r; j++)
      scanf("%d", &MAX[i][j]);
  }

  printf("\nEnter the allocation for each process:\n");
  for (i = 0; i < p; i++)
  {
    printf("For process %d: ", i + 1);
    for (j = 0; j < r; j++)
      scanf("%d", &alloc[i][j]);
  }

  printf("\nEnter the available resources:\n");
  for (i = 0; i < r; i++)
    scanf("%d", &avail[i]);

  do
  {
    process = -1; // Initialize process to indicate no process is selected initially
    // Iterate over each process to find one that can be executed
    for (i = 0; i < p; i++)
    {
      if (!completed[i])
      {              // If the process is not completed
        process = i; // Mark the current process as a candidate for execution
        // Check if the available resources are sufficient to satisfy the needs of this process
        for (j = 0; j < r; j++)
        {
          if (avail[j] < MAX[i][j] - alloc[i][j])
          {               // If not enough resources available
            process = -1; // Reset the process selection
            break;        // Exit the loop for this process
          }
        }
      }
      if (process != -1) // If a process has been selected for execution
        break;           // Exit the loop for process selection
    }
    if (process != -1)
    {                                                          // If a process has been selected for execution
      printf("\nProcess %d runs to completion!", process + 1); // Print the process number
      safeSequence[count] = i;
      // Release the allocated resources of the completed process
      for (j = 0; j < r; j++)
      {
        avail[j] += alloc[process][j]; // Return allocated resources to available pool
        alloc[process][j] = 0;         // Reset the allocation for this process
        MAX[process][j] = 0;           // Reset the maximum requirement for this process (optional)
        completed[process] = 1;        // Mark the process as completed
      }
      count++;
    }
  } while (count != p && process != -1); // Continue until all processes are completed or deadlock is detected

  if (count == p)
  {
    printf("\nThe system is in a safe state!\n");
    printf("Safe Sequence: <");
        for (i = 0; i < p - 1; i++)
            printf("%d, ", safeSequence[i] +1);
        printf("%d>\n", safeSequence[p - 1]+ 1);
    
  }
  else
  {
    printf("\nThe system is in an unsafe state!\n");
  }

  return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main()
{
  int allocated[50] = {0}; // Initialize all blocks as unallocated
  int num_allocated, start, length, additional_blocks, choice;

  printf("Enter how many blocks are already allocated: ");
  scanf("%d", &num_allocated);

  printf("Enter the blocks already allocated: ");
  for (int i = 0; i < num_allocated; i++)
  {
    int block;
    scanf("%d", &block);
    allocated[block] = 1; // Mark the block as allocated
  }

  do
  {
    printf("Enter starting block index and length: ");
    scanf("%d %d", &start, &length);

    additional_blocks = 0;

    if (allocated[start] == 0)
    {
      for (int j = start; j < start + length; j++)
      {
        if (allocated[j] == 0)
        {
          allocated[j] = 1;
          printf("%d --------> %d\n", j, allocated[j]);
        }
        else
        {
          printf("%d Block is already allocated\n", j);
          length++; // Increment length if block is already allocated
          additional_blocks++;
        }
      }
    }
    else
    {
      printf("%d starting block is already allocated\n", start);
    }

    printf("Do you want to enter more file? (Yes - 1 / No - 0): ");
    scanf("%d", &choice);
  } while (choice == 1);

  return 0;
}

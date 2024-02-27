#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_FILES 10
#define MAX_FILENAME_LENGTH 10
#define MAX_DIRECTORY_NAME_LENGTH 10

struct Directory {
    char dname[MAX_DIRECTORY_NAME_LENGTH];
    char fname[MAX_FILES][MAX_FILENAME_LENGTH];
    int fcnt;
};

int main() {
    struct Directory dir;
    int ch, i;
    char fname[MAX_FILENAME_LENGTH];

    dir.fcnt = 0;

    printf("Enter name of directory: ");
    scanf("%s", dir.dname);

    while (1) {
        printf("\n\n1. Create File\t2. Delete File\t3. Search File\n4. Display Files\t5. Exit\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter the name of the file: ");
                scanf("%s", dir.fname[dir.fcnt]);
                dir.fcnt++;
                break;
            case 2:
                printf("Enter the name of the file: ");
                scanf("%s", fname);
                for (i = 0; i < dir.fcnt; i++) {
                    if (strcmp(fname, dir.fname[i]) == 0) {
                        printf("File %s is deleted\n", fname);
                        strcpy(dir.fname[i], dir.fname[dir.fcnt - 1]);
                        dir.fcnt--;
                        break;
                    }
                }
                if (i == dir.fcnt)
                    printf("File %s not found\n", fname);
                break;
            case 3:
                printf("Enter the name of the file: ");
                scanf("%s", fname);
                for (i = 0; i < dir.fcnt; i++) {
                    if (strcmp(fname, dir.fname[i]) == 0) {
                        printf("File %s is found\n", fname);
                        break;
                    }
                }
                if (i == dir.fcnt)
                    printf("File %s not found\n", fname);
                break;
            case 4:
                if (dir.fcnt == 0)
                    printf("Directory is empty\n");
                else {
                    printf("Files in the directory: ");
                    for (i = 0; i < dir.fcnt; i++)
                        printf("\t%s", dir.fname[i]);
                    printf("\n");
                }
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
                break;
        }
    }

    return 0;
}

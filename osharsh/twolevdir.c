#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_DIRECTORIES 10
#define MAX_FILES_PER_DIRECTORY 10
#define MAX_NAME_LENGTH 30

struct Directory {
    char dname[MAX_NAME_LENGTH];
    char fname[MAX_FILES_PER_DIRECTORY][MAX_NAME_LENGTH];
    int fcnt;
};

int main() {
    struct Directory dir[MAX_DIRECTORIES];
    int ch, dcnt = 0, i, k;
    char d[MAX_NAME_LENGTH], f[MAX_NAME_LENGTH];

    while (1) {
        printf("\n\n1. Create Directory\t2. Create File\t3. Delete File\n4. Search File\t\t5. Display\t6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("\nEnter name of directory: ");
                scanf("%s", dir[dcnt].dname);
                dir[dcnt].fcnt = 0;
                dcnt++;
                printf("Directory created\n");
                break;
            case 2:
                printf("\nEnter name of the directory: ");
                scanf("%s", d);
                for (i = 0; i < dcnt; i++) {
                    if (strcmp(d, dir[i].dname) == 0) {
                        printf("Enter name of the file: ");
                        scanf("%s", dir[i].fname[dir[i].fcnt]);
                        dir[i].fcnt++;
                        printf("File created\n");
                        break;
                    }
                }
                if (i == dcnt)
                    printf("Directory %s not found\n", d);
                break;
            case 3:
                printf("\nEnter name of the directory: ");
                scanf("%s", d);
                for (i = 0; i < dcnt; i++) {
                    if (strcmp(d, dir[i].dname) == 0) {
                        printf("Enter name of the file: ");
                        scanf("%s", f);
                        for (k = 0; k < dir[i].fcnt; k++) {
                            if (strcmp(f, dir[i].fname[k]) == 0) {
                                printf("File %s is deleted\n", f);
                                dir[i].fcnt--;
                                strcpy(dir[i].fname[k], dir[i].fname[dir[i].fcnt]);
                                break;
                            }
                        }
                        if (k == dir[i].fcnt)
                            printf("File %s not found\n", f);
                        break;
                    }
                }
                if (i == dcnt)
                    printf("Directory %s not found\n", d);
                break;
            case 4:
                printf("\nEnter name of the directory: ");
                scanf("%s", d);
                for (i = 0; i < dcnt; i++) {
                    if (strcmp(d, dir[i].dname) == 0) {
                        printf("Enter the name of the file: ");
                        scanf("%s", f);
                        for (k = 0; k < dir[i].fcnt; k++) {
                            if (strcmp(f, dir[i].fname[k]) == 0) {
                                printf("File %s is found\n", f);
                                break;
                            }
                        }
                        if (k == dir[i].fcnt)
                            printf("File %s not found\n", f);
                        break;
                    }
                }
                if (i == dcnt)
                    printf("Directory %s not found\n", d);
                break;
            case 5:
                if (dcnt == 0)
                    printf("\nNo Directories\n");
                else {
                    printf("\nDirectory\tFiles\n");
                    for (i = 0; i < dcnt; i++) {
                        printf("%s\t\t", dir[i].dname);
                        for (k = 0; k < dir[i].fcnt; k++)
                            printf("%s\t", dir[i].fname[k]);
                        printf("\n");
                    }
                }
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
                break;
        }
    }

    return 0;
}

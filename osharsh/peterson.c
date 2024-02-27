#include <stdio.h>
#include <pthread.h>
#define NUM 50

void *thread0();
void *thread1();
int accumulator = 0;
int flag_0 = 0;
int flag_1 = 0;
int turn = 0;

int main(int argc, char *argv[])
{
    pthread_t thread[2];
    pthread_create(&thread[0], NULL, thread0, NULL);
    pthread_create(thread0[1], NULL, thread1, NULL);

    pthread_join(thread[0], NULL);
    pthread_join(thread[1], NULL);
}
void *thread0()

{
    int i = 0;
    while (i++ < NUM_ROUNDS)
    {
        flag_0 = 1;
        turn = 1;
        while (flag_1 && turn != 0)
            ;
        flag_0 = 0;
    }
    printf("value of accumlator after %d incremets=%d\n", NUM_ROUNDS, accumulator);
    printf("exiting from thread 0 ..\n");
}
void *thread 1()
{
    int i = 0;
    while (i++ < NUM_ROUNDS)
    {
        flag_1 = 1;
        turn = 0;
        while (flag_0 && turn != 1)
            ;
        accumulator--;
        flag_1 = 0;
        printf("value of accumulator after %d decrements =%d\n", NUM_ROUNDS, accumulator);
        printf("exiting from thread 1..\n");
    }
}

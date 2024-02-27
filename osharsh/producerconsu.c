#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define BUFFER_SIZE 5
#define MAX_ITEMS 20

int buffer[BUFFER_SIZE];
int in = 0, out = 0, produced_count = 0, consumed_count = 0;

sem_t mutex, full, empty;

void *producer(void *arg) {
    while (1) {
        sem_wait(&empty);
        sem_wait(&mutex);
        
        buffer[in] = produced_count + 1;
        printf("Produced: %d\n", buffer[in]);
        in = (in + 1) % BUFFER_SIZE;
        produced_count++;
        
        sem_post(&mutex);
        sem_post(&full);
        
        if (produced_count == MAX_ITEMS)
            break;
    }
    return NULL;
}

void *consumer(void *arg) {
    while (1) {
        sem_wait(&full);
        sem_wait(&mutex);
        
        int item = buffer[out];
        printf("Consumed: %d\n", item);
        out = (out + 1) % BUFFER_SIZE;
        consumed_count++;
        
        sem_post(&mutex);
        sem_post(&empty);
        
        if (consumed_count == MAX_ITEMS)
            break;
    }
    return NULL;
}

int main() {
    pthread_t producer_thread, consumer_thread;
    
    sem_init(&mutex, 0, 1);
    sem_init(&full, 0, 0);
    sem_init(&empty, 0, BUFFER_SIZE);
    
    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer_thread, NULL, consumer, NULL);
    
    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);
    
    sem_destroy(&mutex);
    sem_destroy(&full);
    sem_destroy(&empty);
    
    return 0;
}

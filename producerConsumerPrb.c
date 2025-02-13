#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define BUFFER_SIZE 5  
#define TOTAL_ITEMS 10 

int buffer[BUFFER_SIZE];  
int in = 0, out = 0;      

sem_t empty; 
sem_t full;  

void* producer(void* arg) {
    for (int i = 1; i <= TOTAL_ITEMS; i++) {
        sem_wait(&empty);  

        buffer[in] = i; 
        printf("Producer produced: %d\n", i);
        in = (in + 1) % BUFFER_SIZE;

        sem_post(&full);  

        sleep(1); 
    }
    return NULL;
}

void* consumer(void* arg) {
    for (int i = 1; i <= TOTAL_ITEMS; i++) {
        sem_wait(&full);  

        int item = buffer[out]; 
        printf("Consumer consumed: %d\n", item);
        out = (out + 1) % BUFFER_SIZE; 

        sem_post(&empty);  

        sleep(2); 
    }
    return NULL;
}

int main() {
    pthread_t producer_thread, consumer_thread;

    sem_init(&empty, 0, BUFFER_SIZE); 
    sem_init(&full, 0, 0); 

    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer_thread, NULL, consumer, NULL);

    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    sem_destroy(&empty);
    sem_destroy(&full);

    return 0;
}

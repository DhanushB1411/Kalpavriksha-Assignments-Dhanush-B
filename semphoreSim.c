#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>

sem_t sem; 

void *thread_function(void *arg) {
    sem_wait(&sem); // Wait (decrement semaphore)
    printf("Thread %d is executing\n", *(int *)arg);
    sem_post(&sem); // Signal (increment semaphore)
    return NULL;
}

int main() {
    pthread_t threads[2];
    int args[2] = {1, 2};

    sem_init(&sem, 0, 1); // Initialize semaphore with value 1

    for (int i = 0; i < 2; i++) {
        pthread_create(&threads[i], NULL, thread_function, &args[i]);
    }

    for (int i = 0; i < 2; i++) {
        pthread_join(threads[i], NULL);
    }

    sem_destroy(&sem); // Destroy semaphore
    return 0;
}

#include <pthread.h>
#include <stdio.h>

pthread_mutex_t lock; // Declare mutex

void *thread_function(void *arg) {
    pthread_mutex_lock(&lock); // Lock mutex
    printf("Thread %d is executing\n", *(int *)arg);
    pthread_mutex_unlock(&lock); // Unlock mutex
    return NULL;
}

int main() {
    pthread_t threads[2];
    int args[2] = {1, 2};

    pthread_mutex_init(&lock, NULL); 

    for (int i = 0; i < 2; i++) {
        pthread_create(&threads[i], NULL, thread_function, &args[i]);
    }

    for (int i = 0; i < 2; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&lock); 
    return 0;
}

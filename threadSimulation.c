#include <stdio.h>
#include <pthread.h>
#include <unistd.h> // For usleep

void* fun1(void* arg) {
    for(int i = 0; i < 10; i++) {
        printf("ppppppppppppppppppppp\n");
        sleep(1);
    }
    return NULL;
}

void* fun2(void* arg) {
    for(int i = 0; i < 10; i++) {
        printf("iiiiiiiiiiiiiiiiiiiiiiiii\n");
        sleep(1);
    }
    return NULL;
}

int main() {
    pthread_t thread1, thread2;

    pthread_create(&thread1, NULL, fun1, NULL);
    pthread_create(&thread2, NULL, fun2, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}
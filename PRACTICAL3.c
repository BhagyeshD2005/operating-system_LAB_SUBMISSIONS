#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


void* threadFunction(void* arg) {
    printf("Thread is running...\n");

    for (int i = 0; i < 5; i++) {
        printf("Thread working: %d\n", i);
    }
    printf("Thread is terminating...\n");
    return NULL;
}

int main() {
    pthread_t thread;

    printf("Main thread: creating a new thread.\n");


    if (pthread_create(&thread, NULL, threadFunction, NULL) != 0) {
        perror("Failed to create thread");
        return 1;
    }

        if (pthread_join(thread, NULL) != 0) {
        perror("Failed to join thread");
        return 2;
    }

    printf("Main thread: thread has terminated.\n");
    return 0;
}

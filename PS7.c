#include <stdio.h>
#include <pthread.h>

int counter = 0; // shared variable

void* increment(void* arg) {
    for (int i = 0; i < 100000; i++) {
        counter = counter + 1;
    }
    return NULL;
}

int main() {
    pthread_t thread1;

    // Create a single thread
    pthread_create(&thread1, NULL, increment, NULL);

    // Wait for thread to finish
    pthread_join(thread1, NULL);

    printf("Final Counter Variables Value (Single Thread): %d\n", counter);
    return 0;
}

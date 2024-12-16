#include <stdio.h>
#include <pthread.h>
#define THREADS 4
#define ITERATIONS 100000
int shared_var = 0;
pthread_mutex_t lock;
void *increment(void *arg) {
    for (int i = 0; i < ITERATIONS; i++) {
        pthread_mutex_lock(&lock);
        shared_var++;
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}
int main() {
    pthread_t threads[THREADS];
    pthread_mutex_init(&lock, NULL);
    for (int i = 0; i < THREADS; i++) pthread_create(&threads[i], NULL, increment, NULL);
    for (int i = 0; i < THREADS; i++) pthread_join(threads[i], NULL);
    pthread_mutex_destroy(&lock);
    printf("Final value of shared_var: %d\n", shared_var);
    return 0;
}


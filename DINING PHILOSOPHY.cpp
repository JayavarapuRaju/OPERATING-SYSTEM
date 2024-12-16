#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#define N 5
pthread_mutex_t forks[N];
void* philosopher(void* id) {
    int i = *(int*)id;
    while (1) {
        printf("Philosopher %d is thinking.\n", i);
        usleep(1000);
        pthread_mutex_lock(&forks[i]);
        pthread_mutex_lock(&forks[(i + 1) % N]);
        printf("Philosopher %d is eating.\n", i);
        usleep(1000);
        pthread_mutex_unlock(&forks[(i + 1) % N]);
        pthread_mutex_unlock(&forks[i]);
    }
}
int main() {
    pthread_t t[N];
    int i, ids[N];
    for (i = 0; i < N; i++) pthread_mutex_init(&forks[i], NULL), ids[i] = i;
    for (i = 0; i < N; i++) pthread_create(&t[i], NULL, philosopher, &ids[i]);
    for (i = 0; i < N; i++) pthread_join(t[i], NULL);
    return 0;
}


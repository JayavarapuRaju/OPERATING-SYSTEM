#include <stdio.h>
#include <pthread.h>
void *thread_function(void *arg) {
    printf("This is from thread\n");
    return NULL;
}
int main() {
    pthread_t thread_id;
    pthread_create(&thread_id, NULL, thread_function, NULL);
    pthread_join(thread_id, NULL);
    printf("This is from main thread\n");
    return 0;
}

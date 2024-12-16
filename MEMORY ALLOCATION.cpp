#include <stdio.h>
#include <stdlib.h>
void allocate_memory() {
    int *arr1 = malloc(5 * sizeof(int)), *arr2 = calloc(5, sizeof(int));
    if (!arr1 || !arr2) { perror("Memory allocation failed"); exit(1); }
    for (int i = 0; i < 5; i++) printf("%d ", arr1[i] = i + 1);
    printf("\n");
    for (int i = 0; i < 5; i++) printf("%d ", arr2[i] = (i + 1) * 10);
    free(arr1), free(arr2);
}
int main() {
    allocate_memory();
    return 0;
}


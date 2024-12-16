#include <stdio.h>

void worstFit(int blocks[], int bCount, int processes[], int pCount) {
    int alloc[pCount];
    for (int i = 0; i < pCount; i++) alloc[i] = -1;

    for (int i = 0; i < pCount; i++) {
        int worst = -1;
        for (int j = 0; j < bCount; j++)
            if (blocks[j] >= processes[i] && (worst == -1 || blocks[j] > blocks[worst]))
                worst = j;
        if (worst != -1) {
            alloc[i] = worst;
            blocks[worst] -= processes[i];
        }
    }

    printf("Process No.\tProcess Size\tBlock No.\n");
    for (int i = 0; i < pCount; i++) {
        printf("%d\t\t%d\t\t", i + 1, processes[i]);
        if (alloc[i] != -1)
            printf("%d\n", alloc[i] + 1);
        else
            printf("Not Allocated\n");
    }
}

int main() {
    int blocks[] = {100, 500, 200, 300, 600}, processes[] = {212, 417, 112, 426};
    int bCount = sizeof(blocks) / sizeof(blocks[0]);
    int pCount = sizeof(processes) / sizeof(processes[0]);
    worstFit(blocks, bCount, processes, pCount);
    return 0;
}


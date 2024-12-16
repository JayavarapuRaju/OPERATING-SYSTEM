#include <stdio.h>
void bestFit(int blocks[], int bCount, int processes[], int pCount) {
    int alloc[pCount];
    for (int i = 0; i < pCount; i++) alloc[i] = -1;

    for (int i = 0; i < pCount; i++) {
        int best = -1;
        for (int j = 0; j < bCount; j++) {
            if (blocks[j] >= processes[i] && (best == -1 || blocks[j] < blocks[best])) {
                best = j;
            }
        }
        if (best != -1) {
            alloc[i] = best;
            blocks[best] -= processes[i];
        }
    }
    printf("Process No.\tProcess Size\tBlock No.\n");
    for (int i = 0; i < pCount; i++) {
        printf("%d\t\t%d\t\t%s\n", i + 1, processes[i], alloc[i] != -1 ? "Block " : "Not Allocated");
    }
}
int main() {
    int blocks[] = {100, 500, 200, 300, 600};
    int processes[] = {212, 417, 112, 426};
    bestFit(blocks, sizeof(blocks) / sizeof(blocks[0]), processes, sizeof(processes) / sizeof(processes[0]));
    return 0;
}

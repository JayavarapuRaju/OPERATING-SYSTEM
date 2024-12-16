#include <stdio.h>
#include <stdbool.h>
#define MAX 10

int allocation[MAX][MAX], max[MAX][MAX], need[MAX][MAX], available[MAX], n, m;

void input() {
    printf("Enter processes, resources: "); scanf("%d %d", &n, &m);
    printf("Allocation matrix:\n"); for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) scanf("%d", &allocation[i][j]);
    printf("Max matrix:\n"); for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) scanf("%d", &max[i][j]);
    printf("Available resources: "); for (int i = 0; i < m; i++) scanf("%d", &available[i]);
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) need[i][j] = max[i][j] - allocation[i][j];
}

bool isSafe() {
    int work[MAX], safeSequence[MAX], count = 0; bool finish[MAX] = {false};
    for (int i = 0; i < m; i++) work[i] = available[i];
    while (count < n) {
        bool found = false;
        for (int i = 0; i < n; i++) {
            if (!finish[i]) {
                bool canProceed = true;
                for (int j = 0; j < m; j++) if (need[i][j] > work[j]) { canProceed = false; break; }
                if (canProceed) {
                    for (int j = 0; j < m; j++) work[j] += allocation[i][j];
                    safeSequence[count++] = i; finish[i] = true; found = true;
                }
            }
        }
        if (!found) return printf("Not in safe state.\n"), false;
    }
    printf("Safe sequence: "); for (int i = 0; i < n; i++) printf("P%d ", safeSequence[i]); printf("\n");
    return true;
}

int main() { input(); isSafe(); return 0; }

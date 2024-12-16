#include <stdio.h>
struct Process { int pid, burstTime, waitingTime, turnAroundTime; };

void calculateTimes(struct Process p[], int n) {
    for (int i = 0; i < n; i++) {
        p[i].waitingTime = (i == 0) ? 0 : p[i - 1].waitingTime + p[i - 1].burstTime;
        p[i].turnAroundTime = p[i].waitingTime + p[i].burstTime;
    }
    printf("\nPID\tBurst\tWait\tTurnaround\n");
    for (int i = 0; i < n; i++)
        printf("%d\t%d\t%d\t%d\n", p[i].pid, p[i].burstTime, p[i].waitingTime, p[i].turnAroundTime);
}
void sortByBurst(struct Process p[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (p[j].burstTime > p[j + 1].burstTime) {
                struct Process temp = p[j]; p[j] = p[j + 1]; p[j + 1] = temp;
            }
}
int main() {
    int n; 
    printf("Enter number of processes: "); 
    scanf("%d", &n);
    struct Process p[n];
    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1; 
        printf("Enter burst time for process %d: ", i + 1); 
        scanf("%d", &p[i].burstTime);
    }
    sortByBurst(p, n); 
    calculateTimes(p, n);
    return 0;
}

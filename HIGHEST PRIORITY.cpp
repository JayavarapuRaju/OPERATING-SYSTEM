#include <stdio.h>
struct Process { int pid, burstTime, waitingTime, turnAroundTime, priority; };
void priorityScheduling(struct Process p[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (p[j].priority < p[j + 1].priority) {
                struct Process temp = p[j]; 
                p[j] = p[j + 1]; 
                p[j + 1] = temp;
            }
    p[0].waitingTime = 0;
    for (int i = 1; i < n; i++) 
        p[i].waitingTime = p[i - 1].waitingTime + p[i - 1].burstTime;
    for (int i = 0; i < n; i++) 
        p[i].turnAroundTime = p[i].waitingTime + p[i].burstTime;
}
int main() {
    int n; 
    printf("Enter number of processes: "); 
    scanf("%d", &n);
    struct Process p[n];
    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Enter burst time and priority: "); 
        scanf("%d %d", &p[i].burstTime, &p[i].priority);
    }
    priorityScheduling(p, n);
    printf("\nPID\tBurst\tWait\tTurnaround\tPriority\n");
    for (int i = 0; i < n; i++)
        printf("%d\t%d\t%d\t%d\t\t%d\n", p[i].pid, p[i].burstTime, p[i].waitingTime, p[i].turnAroundTime, p[i].priority);
    return 0;
}

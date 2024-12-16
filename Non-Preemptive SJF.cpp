#include <stdio.h>
struct Process {
    int id, burstTime, waitingTime, turnaroundTime;
};
int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    struct Process proc[n];
    for (int i = 0; i < n; i++) {
        proc[i].id = i + 1;
        printf("Burst time for process %d: ", i + 1);
        scanf("%d", &proc[i].burstTime);
    }
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (proc[i].burstTime > proc[j].burstTime) {
                struct Process temp = proc[i];
                proc[i] = proc[j];
                proc[j] = temp;
            }
    for (int i = 0; i < n; i++) {
        proc[i].waitingTime = (i == 0) ? 0 : proc[i - 1].waitingTime + proc[i - 1].burstTime;
        proc[i].turnaroundTime = proc[i].waitingTime + proc[i].burstTime;
    }
    printf("Process ID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++)
        printf("%d\t\t%d\t\t%d\t\t%d\n", proc[i].id, proc[i].burstTime, proc[i].waitingTime, proc[i].turnaroundTime);
    return 0;
}

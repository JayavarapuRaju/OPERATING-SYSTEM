
#include <stdio.h>

struct Process {
    int pid, at, bt, pr, rt, wt, tat, ct;
};
int main() {
    int n, completed = 0, time = 0, minPr, shortest;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    struct Process p[n];
    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Enter AT, BT, PR for P%d: ", i + 1);
        scanf("%d %d %d", &p[i].at, &p[i].bt, &p[i].pr);
        p[i].rt = p[i].bt;
    }
    while (completed < n) {
        minPr = 1e9, shortest = -1;
        for (int i = 0; i < n; i++)
            if (p[i].at <= time && p[i].rt > 0 && p[i].pr < minPr)
                minPr = p[i].pr, shortest = i;
        if (shortest == -1) { time++; continue; }
        p[shortest].rt--;
        if (p[shortest].rt == 0) {
            p[shortest].ct = ++time;
            p[shortest].tat = p[shortest].ct - p[shortest].at;
            p[shortest].wt = p[shortest].tat - p[shortest].bt;
            completed++;
        } else time++;
    }
    printf("\nPID\tAT\tBT\tPR\tWT\tTAT\n");
    for (int i = 0; i < n; i++)
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].at, p[i].bt, p[i].pr, p[i].wt, p[i].tat);
    return 0;
}


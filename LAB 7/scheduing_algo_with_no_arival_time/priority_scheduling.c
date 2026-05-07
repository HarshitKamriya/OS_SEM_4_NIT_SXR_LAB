#include <stdio.h>

#define MAX 30

struct Process {
    int id;
    int bt;   // burst time
    int pt;   // priority
    int wt;   // waiting time
    int tat;  // turnaround time
};

int main() {
    struct Process p[MAX];
    int n;
    float total_wt = 0, total_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter burst time and priority for each process:\n");
    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        printf("Process %d: ", i + 1);
        scanf("%d %d", &p[i].bt, &p[i].pt);
    }

    // Sort processes by priority (lower number = higher priority)
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (p[j].pt < p[i].pt) {
                struct Process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    // Calculate waiting time and turnaround time
    p[0].wt = 0;
    p[0].tat = p[0].bt;
    for (int i = 1; i < n; i++) {
        p[i].wt = p[i - 1].wt + p[i - 1].bt;
        p[i].tat = p[i].wt + p[i].bt;
    }

    printf("\nProcess\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        total_wt += p[i].wt;
        total_tat += p[i].tat;
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", p[i].id, p[i].bt, p[i].pt, p[i].wt, p[i].tat);
    }

    printf("\nAverage Waiting Time = %.2f", total_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", total_tat / n);

    return 0;
}

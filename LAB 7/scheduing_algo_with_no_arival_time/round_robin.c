#include <stdio.h>

#define MAX 30

int main() {
    int n, bt[MAX], wt[MAX], tat[MAX], rem_bt[MAX];
    int quantum, time = 0;
    float total_wt = 0, total_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter burst times of processes:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
        rem_bt[i] = bt[i];  // remaining burst time
    }

    printf("Enter time quantum: ");
    scanf("%d", &quantum);

    // Round Robin scheduling
    while (1) {
        int done = 1;
        for (int i = 0; i < n; i++) {
            if (rem_bt[i] > 0) {
                done = 0;
                if (rem_bt[i] > quantum) {
                    time += quantum;
                    rem_bt[i] -= quantum;
                } else {
                    time += rem_bt[i];
                    wt[i] = time - bt[i];
                    rem_bt[i] = 0;
                    tat[i] = time;
                }
            }
        }
        if (done == 1)
            break;
    }

    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
        printf("%d\t%d\t\t%d\t\t%d\n", i + 1, bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time = %.2f", total_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", total_tat / n);

    return 0;
}

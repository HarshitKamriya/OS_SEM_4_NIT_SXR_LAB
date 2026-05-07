#include<stdio.h>
#define max 30

struct Process {
    int pid;
    int arrival;
    int burst;
    int wt;
    int tat;
};

int main(){
    int i, j, n;
    float awt = 0, atat = 0;
    struct Process proc[max], temp;
    
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    for(i = 0; i < n; i++){
        proc[i].pid = i + 1;
        printf("Enter arrival time of process %d: ", i+1);
        scanf("%d", &proc[i].arrival);
        printf("Enter burst time of process %d: ", i+1);
        scanf("%d", &proc[i].burst);
    }
    
    // Sort by arrival time
    for(i = 0; i < n; i++){
        for(j = i + 1; j < n; j++){
            if(proc[i].arrival > proc[j].arrival){
                temp = proc[i];
                proc[i] = proc[j];
                proc[j] = temp;
            }
        }
    }
    
    // Calculate waiting time and turnaround time
    int completion = 0;
    for(i = 0; i < n; i++){
        if(completion < proc[i].arrival){
            completion = proc[i].arrival;
        }
        completion += proc[i].burst;
        proc[i].tat = completion - proc[i].arrival;
        proc[i].wt = proc[i].tat - proc[i].burst;
    }
    
    printf("\nProcess\tArrival\tBurst\tWaiting\tTAT\n");
    for(i = 0; i < n; i++){
        awt += proc[i].wt;
        atat += proc[i].tat;
        printf("%d\t%d\t%d\t%d\t%d\n", proc[i].pid, proc[i].arrival, proc[i].burst, proc[i].wt, proc[i].tat);
    }
    
    awt = awt / n;
    atat = atat / n;
    printf("\nAverage Waiting Time: %.2f\n", awt);
    printf("Average Turnaround Time: %.2f\n", atat);
    
    return 0;
}

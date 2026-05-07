#include<stdio.h>
#define max 30

struct Process {
    int pid;
    int arrival;
    int burst;
    int priority;
    int wt;
    int tat;
    int completed;
};

int main(){
    int i, j, n, completed = 0;
    float awt = 0, atat = 0;
    struct Process proc[max], temp;
    
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    for(i = 0; i < n; i++){
        proc[i].pid = i + 1;
        proc[i].completed = 0;
        printf("Enter arrival time of process %d: ", i+1);
        scanf("%d", &proc[i].arrival);
        printf("Enter burst time of process %d: ", i+1);
        scanf("%d", &proc[i].burst);
        printf("Enter priority of process %d (lower number = higher priority): ", i+1);
        scanf("%d", &proc[i].priority);
    }
    
    int time = 0;
    printf("\nProcess\tArrival\tBurst\tPriority\tWaiting\tTAT\n");
    
    // Schedule processes
    while(completed < n){
        int minPriority = 999, minIdx = -1;
        
        // Find process with highest priority (lowest number) among available processes
        for(i = 0; i < n; i++){
            if(proc[i].completed == 0 && proc[i].arrival <= time && proc[i].priority < minPriority){
                minPriority = proc[i].priority;
                minIdx = i;
            }
        }
        
        // If no process available, move time to next arrival
        if(minIdx == -1){
            for(i = 0; i < n; i++){
                if(proc[i].completed == 0 && proc[i].arrival > time){
                    time = proc[i].arrival;
                    break;
                }
            }
            continue;
        }
        
        // Execute the process
        time += proc[minIdx].burst;
        proc[minIdx].tat = time - proc[minIdx].arrival;
        proc[minIdx].wt = proc[minIdx].tat - proc[minIdx].burst;
        proc[minIdx].completed = 1;
        completed++;
        
        printf("%d\t%d\t%d\t%d\t\t%d\t%d\n", proc[minIdx].pid, proc[minIdx].arrival, proc[minIdx].burst, proc[minIdx].priority, proc[minIdx].wt, proc[minIdx].tat);
    }
    
    for(i = 0; i < n; i++){
        awt += proc[i].wt;
        atat += proc[i].tat;
    }
    
    awt = awt / n;
    atat = atat / n;
    printf("\nAverage Waiting Time: %.2f\n", awt);
    printf("Average Turnaround Time: %.2f\n", atat);
    
    return 0;
}

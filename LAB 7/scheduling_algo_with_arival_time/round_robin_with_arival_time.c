#include<stdio.h>
#define max 30

struct Process {
    int pid;
    int arrival;
    int burst;
    int remaining;
    int wt;
    int tat;
    int completion;
};

int main(){
    int i, n, tq, time = 0, completed = 0;
    float awt = 0, atat = 0;
    struct Process proc[max], temp;
    
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    printf("Enter time quantum: ");
    scanf("%d", &tq);
    
    for(i = 0; i < n; i++){
        proc[i].pid = i + 1;
        printf("Enter arrival time of process %d: ", i+1);
        scanf("%d", &proc[i].arrival);
        printf("Enter burst time of process %d: ", i+1);
        scanf("%d", &proc[i].burst);
        proc[i].remaining = proc[i].burst;
        proc[i].completion = 0;
    }
    
    printf("\nProcess\tArrival\tBurst\tWaiting\tTAT\n");
    
    while(completed < n){
        int executed = 0;
        
        // Round robin scheduling
        for(i = 0; i < n; i++){
            if(proc[i].remaining > 0 && proc[i].arrival <= time){
                executed = 1;
                
                if(proc[i].remaining <= tq){
                    time += proc[i].remaining;
                    proc[i].completion = time;
                    proc[i].tat = proc[i].completion - proc[i].arrival;
                    proc[i].wt = proc[i].tat - proc[i].burst;
                    proc[i].remaining = 0;
                    completed++;
                    
                    printf("%d\t%d\t%d\t%d\t%d\n", proc[i].pid, proc[i].arrival, proc[i].burst, proc[i].wt, proc[i].tat);
                }
                else{
                    time += tq;
                    proc[i].remaining -= tq;
                }
            }
        }
        
        // If no process executed, move time to next arrival
        if(executed == 0){
            int minArrival = 999;
            for(i = 0; i < n; i++){
                if(proc[i].remaining > 0 && proc[i].arrival > time){
                    if(proc[i].arrival < minArrival){
                        minArrival = proc[i].arrival;
                    }
                }
            }
            if(minArrival != 999){
                time = minArrival;
            }
        }
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

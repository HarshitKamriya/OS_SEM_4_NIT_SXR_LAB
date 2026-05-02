#include<stdio.h>
#define max 30
void main(){
        int i,j,n,bt[max],wt[max],tat[max];
        float awt = 0,atat = 0;
        printf("Enter the no of process:  ");
        scanf("%d",&n);
        for(i=0;i<n;i++){
                printf("Enter the burst time of the proceses: %d ",i+1);
                scanf("%d",&bt[i]);
        }
        printf("process\t burst time \t waiting time \t TAT \n");
        for(i=0;i<n;i++){
                wt[i]=0;
                tat[i] = 0;
                for(j=0;j<i;j++){
                        wt[i] = wt[i] + bt[j];
                }
                tat[i] = wt[i] + bt[i];
                awt = awt + wt[i];
                atat = atat + tat[i];
                printf("%d\t%d\t\t%d\t%d\n",i+1,bt[i],wt[i],tat[i]);
        }
        awt = awt/n;
        atat = atat/n;
        printf("%.2f\t%.2f",awt,atat);
        printf("%.2f\t%f",awt,atat);
}
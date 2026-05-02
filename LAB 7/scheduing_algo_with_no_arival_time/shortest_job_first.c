#include<stdio.h>
#define max 30

void merge(int arr[],int sp,int m,int ep);
void sort(int arr[],int sp,int ep);
int main(){
        int i,j,n,bt[max],wt[max],tat[max];
        float awt = 0,atat = 0;
        printf("Enter the no of process:  ");
        scanf("%d",&n);
        for(i=0;i<n;i++){
                printf("Enter the burst time of the proceses: %d ",i+1);
                scanf("%d",&bt[i]);
        }
        sort(bt,0,n-1);
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
        return 0;
}
void sort(int arr[],int sp,int ep){
        if(sp>=ep) return;
        int m  =  (sp+ep)/2;
        sort(arr,sp,m);
        sort(arr,m+1,ep);
        merge(arr,sp,m,ep);

}
void merge(int arr[],int sp,int m,int ep){
        int temp[ep-sp+1];
        int p1 =sp;
        int p2 = m+1;
        int p3 = 0;
        while(p1<=m && p2<=ep){
                if(arr[p1] <arr[p2]) temp[p3++] = arr[p1++];
                else temp[p3++] = arr[p2++];
        }
        while(p1<=m) temp[p3++] = arr[p1++];
        while(p2<=ep) temp[p3++] = arr[p2++];
        for(int i=0;i<ep-sp+1;i++){
                arr[sp+i] = temp[i];
        }
}
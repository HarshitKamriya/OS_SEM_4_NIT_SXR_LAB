// first come first serve disk scheduling
#include<stdio.h>
int main(){
    int t[20],n,i,j,tohm[20],tot=0,float avhm;
    cirscr();
    printf("Enter the no. of tracks");
    scanf("%d",&n)
    printf("Enter the tracks to be traversed");
    for(i=2;i<n+2;i++){
        scanf("%d",&t*i+);
    }
    for(i=1;i<n+1;i++){
        tohm[i] = t[i+1]-t[i];
        if(tohm[i]<0) tohm[i] = tohm[i]*(-1);
    }











    return 0;
}
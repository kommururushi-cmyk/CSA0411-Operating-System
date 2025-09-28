#include <stdio.h>
#include <limits.h>

int main(){
    int n; printf("Number of processes: "); scanf("%d", &n);
    int bt[n], rem[n], pr[n];
    for(int i=0;i<n;i++){ printf("P%d burst: ", i+1); scanf("%d", &bt[i]); printf("P%d priority (lower = higher): ", i+1); scanf("%d", &pr[i]); rem[i]=bt[i]; }

    int completed=0, t=0;
    int wt[n]; for(int i=0;i<n;i++) wt[i]=0;
    while (completed < n){
        int idx=-1, best=INT_MAX;
        for(int i=0;i<n;i++) if (rem[i]>0 && pr[i]<best){ best=pr[i]; idx=i; }
        if (idx==-1){ t++; continue; }
        rem[idx]--;
        if (rem[idx]==0){ completed++; int finish=t+1; wt[idx]=finish - bt[idx]; }
        t++;
    }
    printf("P\tBT\tPR\tWT\tTAT\n"); double awt=0, atat=0; int tat;
    for(int i=0;i<n;i++){ tat=bt[i]+wt[i]; printf("P%d\t%d\t%d\t%d\t%d\n", i+1, bt[i], pr[i], wt[i], tat); awt+=wt[i]; atat+=tat; }
    printf("Avg WT=%.2f Avg TAT=%.2f\n", awt/n, atat/n);
    return 0;
}

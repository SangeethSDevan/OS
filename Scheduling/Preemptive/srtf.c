#include <stdio.h>
struct process{
    int id;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
};
void srtf(struct process p[],int n){
    int remaining[n],isComplete[n];
    int time=0,complete=0;
    for(int i=0;i<n;i++){
        remaining[i]=p[i].bt;
        isComplete[i]=0;
    }
    int prev=-1;
    while(complete<n){
        int sProcess=-1,minTime=__INT_MAX__;
        for(int i=0;i<n;i++){
            if(p[i].at<=time && !isComplete[i] && remaining[i]<minTime && remaining[i]!=0){
                minTime=remaining[i];
                sProcess=i;
            }
        }
        if(sProcess==-1){
            time++;
            continue;
        }
        if(sProcess!=prev){
            printf(" P%d (%d - ",p[sProcess].id,time);
        }
        remaining[sProcess]--;
        time++;

        if(remaining[sProcess]==0){
            isComplete[sProcess]=1;
            complete++;
            p[sProcess].ct=time;
            p[sProcess].tat=p[sProcess].ct-p[sProcess].at;
            p[sProcess].wt=p[sProcess].tat-p[sProcess].bt;

            printf("%d ) |",time);
        }else if(sProcess!=prev){
            printf("%d ) |",time);
        }
        prev=sProcess;
    }
}
int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct process p[n];
    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        printf("Enter arrival time and burst time for process %d: ", p[i].id);
        scanf("%d %d", &p[i].at, &p[i].bt);
    }

    printf("Gantt Chart:\n");
    srtf(p, n);

    printf("\nID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", p[i].id, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }

    return 0;
}
#include <stdio.h>
struct process{
    int id;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
    int priority;
};
void preemptivePrior(struct process p[],int n){
   int isCompleted[n],remaining[n],time=0,completed=0;
   for(int i=0;i<n;i++){
    isCompleted[i]=0;
    remaining[i]=p[i].bt;
   }
   int prev=-1;
    while(completed<n){
        int maxPriority=__INT_MAX__,minIndex=-1;
        for(int i=0;i<n;i++){
            if(p[i].at<time && remaining[i]>0 && p[i].priority<maxPriority && !isCompleted[i]){
                maxPriority=p[i].priority;
                minIndex=i;
            }
        }
        if(minIndex==-1){
            time++;
            continue;
        }
        if(prev!=minIndex){
            if(prev!=-1 && remaining[prev]>0)
                printf("%d ) ",time);
            printf(" P%d ( %d - ",p[minIndex].id,time);
        }
        remaining[minIndex]--;
        time++;

        if(remaining[minIndex]==0){
            p[minIndex].ct=time;
            p[minIndex].tat=p[minIndex].ct-p[minIndex].at;
            p[minIndex].wt=p[minIndex].tat-p[minIndex].bt;
            completed++;
            isCompleted[minIndex]=1;
            printf("%d ) ",time);
        }
        prev=minIndex;
    }
}   
int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct process p[n];

    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        printf("Enter arrival time, burst time, and priority for process %d: ", p[i].id);
        scanf("%d %d %d", &p[i].at, &p[i].bt, &p[i].priority);
    }

    int remaining[n];
    for (int i = 0; i < n; i++) {
        remaining[i] = p[i].bt;
    }

    printf("Gantt Chart:\n");
    preemptivePrior(p, n);

    printf("\nID\tAT\tBT\tPriority\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t\t%d\t%d\t%d\n", p[i].id, p[i].at, p[i].bt, p[i].priority, p[i].ct, p[i].tat, p[i].wt);
    }

    return 0;
}
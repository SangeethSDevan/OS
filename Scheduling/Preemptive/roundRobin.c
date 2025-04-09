#include <stdio.h>
struct process{
    int id;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
    int rt;
};
void sort(struct process p[],int n){
    for(int i=0;i<n;i++){
        if(p[i].at>p[i+1].at){
            struct process temp=p[i];
            p[i]=p[i+1];
            p[i+1]=temp;
        }
    }
}
void roundRobin(struct process p[],int n,int quantam){
    int completed=0,time=0;
    int isComplete[n];
    for(int i=0;i<n;i++){
        isComplete[i]=0;
    }
    while(completed<n){
        int flag=0;
        for(int i=0;i<n;i++){
            if(p[i].at<=time && !isComplete[i]){
                flag=1;
                if(p[i].rt<=quantam){
                    time+=p[i].rt;
                    p[i].rt=0;
                    p[i].ct=time;
                    p[i].tat=p[i].ct-p[i].at;
                    p[i].wt=p[i].tat-p[i].bt;
                    isComplete[i]=1;
                    completed++;
                    printf(" P%d (%d - %d) |",p[i].id,time-p[i].bt,time);
                }else{
                    p[i].rt-=quantam;
                    printf(" P%d (%d - %d) |",p[i].id,time,time+quantam);
                    time+=quantam;
                }
            }
        }
        if(!flag){
            time++;
        }
    }
    printf("\n");
}
int main() {
    int n, quantam;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct process p[n];
    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        printf("Enter arrival time and burst time for process %d: ", p[i].id);
        scanf("%d %d", &p[i].at, &p[i].bt);
        p[i].rt = p[i].bt;
    }

    printf("Enter the time quantum: ");
    scanf("%d", &quantam);

    sort(p, n);

    printf("Gantt Chart:\n");
    roundRobin(p, n, quantam);

    printf("\nID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", p[i].id, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }

    return 0;
}
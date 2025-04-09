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
void sort(struct process p[],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1-i;j++){
            if(p[j].at>p[j+1].at){
                struct process temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }
}
void pPrior(struct process p[],int n){
    int time=0,completed=0;
    int isComplete[n];
    for(int i=0;i<n;i++){
        isComplete[i]=0;
    }
    while(completed<n){
        int highP=-1,sProcess=-1;
        for(int i=0;i<n;i++){
            if(p[i].at<=time && !isComplete[i]){
                if(highP==-1||p[i].priority<highP){
                    highP=p[i].priority;
                    sProcess=i;
                }
            }
        }
        if(sProcess==-1){
            time++;
            continue;
        }
        p[sProcess].ct=time+p[sProcess].bt;
        printf(" P%d (%d - %d) | ",p[sProcess].id,time,p[sProcess].ct);
        time=p[sProcess].ct;
        p[sProcess].tat=p[sProcess].ct-p[sProcess].at;
        p[sProcess].wt=p[sProcess].tat-p[sProcess].bt;
        completed++;
        isComplete[sProcess]=1;
    }
}
void display(struct process p[],int n){
    printf("ID\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i=0;i<n;i++){
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",p[i].id,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
    }
}
int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct process p[n];

    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        printf("Enter arrival time, burst time and priority for process %d: ", p[i].id);
        scanf("%d %d %d", &p[i].at, &p[i].bt,&p[i].priority);
    }

    pPrior(p, n);
    display(p, n);

    return 0;
}
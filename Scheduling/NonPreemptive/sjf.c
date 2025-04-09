#include <stdio.h>
struct process{
    int id;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
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
void sjf(struct process p[],int n){
    sort(p,n);
    int completed=0,isComplete[n];
    int time=0;
    for(int i=0;i<n;i++){
        isComplete[i]=0;
    }
    while(completed<n){
        int shortestBT=-1,sProcess=-1;
        for(int i=0;i<n;i++){
            if(!isComplete[i] && p[i].at<=time){
                if(p[i].bt<shortestBT || shortestBT==-1){
                    shortestBT=p[i].bt;
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
    printf("\n");
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
        printf("Enter arrival time and burst time for process %d: ", p[i].id);
        scanf("%d %d", &p[i].at, &p[i].bt);
    }

    sjf(p, n);
    display(p, n);

    return 0;
}
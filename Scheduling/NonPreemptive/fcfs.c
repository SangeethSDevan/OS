#include <stdio.h>

struct process {
    int id;
    int at;
    int bt;
    int wt;
    int ct;
    int tat;
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
void fcfs(struct process p[],int n){
    sort(p,n);
    int time=0;
    float tatAvg=0,wtAvg=0;

    for(int i=0;i<n;i++){
        if(time<p[i].at){
            time=p[i].at;
        }
        p[i].ct=time+p[i].bt;
        time=p[i].ct;
        p[i].tat=p[i].ct-p[i].at;
        p[i].wt=p[i].tat-p[i].bt;

        tatAvg+=p[i].tat;
        wtAvg+=p[i].wt;
    }
    printf("Average tat: %.3f\n",tatAvg/n);
    printf("AVerage wt: %.3f\n",wtAvg/n);
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

    fcfs(p, n);
    display(p, n);

    return 0;
}
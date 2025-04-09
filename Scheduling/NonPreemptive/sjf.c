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
    int shortIndex=0,time=0;
    for(int i=0;i<n;i++){
        shortIndex=i;
        for(int j=i;j<n;j++){
            if(p[j].bt<p[shortIndex].bt && p[j].at<time){
                shortIndex=j;
            }
        }
        if(shortIndex!=i){
            struct process temp=p[i];
            p[i]=p[shortIndex];
            p[shortIndex]=temp;
        }
        if(time<p[i].at){
            time=p[i].at;
        }
        printf("| P%d ",p[i].id);
        p[i].ct=time+p[i].bt;
        time=p[i].ct;
        p[i].tat=p[i].ct-p[i].at;
        p[i].wt=p[i].tat-p[i].bt;
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
#include <stdio.h>
struct process{
    int id;
    int at;
    int bt;
    int rt;
    int tat;
    int wt;
    int priority;
};
void preemptivePriority(struct process p[],int n){
    int completed=0,time=0;
    while(completed<n){
        int minIndex=-1;
        int maxPriority=__INT_MAX__;
        for(int i=0;i<n;i++){
            if(p[i].rt>0 && p[i].at<=time && p[i].priority<maxPriority){
                minIndex=i;
                maxPriority=p[i].priority;
            }
        }
        if(minIndex==-1){
            time++;
            continue;
        }
        p[minIndex].rt--;
        time++;

        if(p[minIndex].rt==0){
            p[minIndex].tat=time-p[minIndex].at;
            p[minIndex].wt=p[minIndex].tat-p[minIndex].bt;
            completed++;
        }
    }
}
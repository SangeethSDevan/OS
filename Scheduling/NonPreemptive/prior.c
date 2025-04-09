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
    int time=0;
    float avgTAT=0,avgWT=0;
    for(int i=0;i<n;i++){
        int selected=-1;
        int highestPriority=__INT_MAX__;
        for(int j=0;j<n;j++){
            if(p[i].at<time && p[i].priority<highestPriority){
                highestPriority=p[i].priority;
                selected=i;
            }
        }

        if(selected==-1){
            selected=i;
            time=p[i].at;
        }

        if(selected!=i){
            struct process temp=p[i];
            p[i]=p[selected];
            p[selected]=temp;
        }
        if(time<p[i].at){
            time=p[i].at;
        }
    }
}
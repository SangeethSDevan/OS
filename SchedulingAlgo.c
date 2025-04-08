#include <stdio.h>

struct process{
    int id,arrivalT,burstT,completionT,turnaraoundT,waitingT;
};

void swap(struct process *a,struct process *b){
    struct process temp=*a;
    *a=*b;
    *b=temp;
}

void fcfs(struct process p[],int n){
    int time=0;
    for(int i=0;i<n;i++){
        if(time<p[i].arrivalT)
            time=p[i].arrivalT;
        p[i].completionT=time+p[i].burstT;
        time=p[i].completionT;
        p[i].turnaraoundT=p[i].completionT-p[i].arrivalT;
        p[i].waitingT=p[i].turnaraoundT-p[i].burstT;
    }
}
void sjf(struct process p[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j=n-1-i;j++){
            if(p[j].arrivalT>p[j+1].arrivalT) swap(&p[j],&p[j+1]);
        }
    }

    int time=0;
    for( int i=0;i<n;i++){
        int shortIndex=i;
        for(int j=i;j<n;j++){
            if(p[j].arrivalT<=time&&p[j].burstT<p[shortIndex].burstT){
                shortIndex=j;
            }
        }
        if(shortIndex!=i){
            swap(&p[i],&p[shortIndex]);
        }
        if(time<p[i].arrivalT)
            time=p[i].arrivalT;
        p[i].completionT=time+p[i].burstT;
        time=p[i].completionT;
        p[i].turnaraoundT=p[i].completionT-p[i].arrivalT;
        p[i].waitingT=p[i].turnaraoundT-p[i].burstT;
    }
}
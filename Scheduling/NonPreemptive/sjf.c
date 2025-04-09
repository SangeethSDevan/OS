#include <stdio.h>
struct process{
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
};
void sort(struct process p[],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1-i;j++){
            if(p[j].bt>p[j+1].bt){
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
            p[shortIndex]=p[i+1];
        }
        if(time<p[i].at){
            time=p[i].at;
        }

        p[i].ct=time+p[i].bt;
        time=p[i].ct;
        p[i].tat=p[i].ct-p[i].at;
        p[i].wt=p[i].tat-p[i].bt;
    }
}
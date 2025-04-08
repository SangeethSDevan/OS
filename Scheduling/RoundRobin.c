#include <stdio.h>
struct process{
    int id;
    int at;
    int bt;
    int rt;
    int tat;
    int wt;
};
void roundRobin(struct process p[],int n,int quantam){  
   int completed=0,time=0;
   while(completed<n){
    for(int i=0;i<n;i++){
        if(p[i].rt>0 && p[i].at<=time){
            int execTime=(p[i].rt>quantam)?quantam:p[i].rt;
            time+=execTime;
            p[i].rt-=execTime;


            if(p[i].rt==0){
                p[i].tat=time-p[i].at;
                p[i].wt=p[i].tat-p[i].bt;
                completed++;
            }
        }
    }
   }
}
int main(){

}
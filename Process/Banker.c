#include <stdio.h>
#define MAX 10

void getSequence(int process,int resource,int available[],int max[][MAX],int allocation[][MAX]){
    int finish[MAX]={0};
    int work[MAX];
    int safeSequence[MAX];

    for(int i=0;i<resource;i++){
        work[i]=available[i];
    }

    int count=0;
    while(count<process){
        int found=0;
        for(int i=0;i<process;i++){
            if(!finish[i]){
                int canBeAllocated=1;
                for(int j=0;j<resource;j++){
                    if(max[i][j]-allocation[i][j]>work[j]){
                        canBeAllocated=0;
                        break;
                    }
                }
                if(canBeAllocated){
                    safeSequence[count++]=i;
                    finish[i]=1;
                    found=1;
                    for(int r=0;r<resource;r++){
                        work[i]+=allocation[i][r];
                    }
                }
            }
        }
    }
}
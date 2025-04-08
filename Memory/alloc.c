#include <stdio.h>

void firstfit(int process[],int block[],int n,int m){
    int tempMemory[m],alloc[n],waste[n];
    for(int i=0;i<m;i++){
        tempMemory[i]=block[i];
    }
    for(int i=0;i<n;i++){
        alloc[i]=-1;
        waste[i]=0;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(process[i]<=tempMemory[j]){
                waste[i]=tempMemory[j]-process[i];
                tempMemory[j]-=process[i];
                alloc[i]=j;
                break;
            }
        }
    }
    //DISPLAY THE ALLOCTION DETAILS
}
void bestfit(int process[],int block[],int n,int m){
    int tempMemory[m],waste[n],alloc[n];
    int minWaste,bestIndex;
    for(int i=0;i<n;i++){
        tempMemory[i]=block[i];
    }
    for(int i=0;i<n;i++){
        alloc[i]=-1;
        waste[i]=0;
    }
    for(int i=0;i<n;i++){
        minWaste=__INT_MAX__;
        bestIndex=-1;
        for(int j=0;j<m;j++){
            if(process[i]<=tempMemory[j]){
                int waste=tempMemory[j]-process[i];
                if(waste<minWaste){
                    minWaste=waste;
                    bestIndex=j;
                }
            }
        }
        if(bestIndex!=-1){
            waste[i]=minWaste;
            tempMemory[bestIndex]-=process[i];
            alloc[i]=bestIndex;
        }
    }
}
void worstfit(int process[],int block[],int n,int m){
    int worstIndex,maxWaste,tempMemory[n],waste[n],alloc[n];
    for(int i=0;i<m;i++){
        tempMemory[i]=block[i];
    }
    for(int i=0;i<n;i++){
        alloc[i]=-1;
        waste[i]=0;
    }
    for(int i=0;i<n;i++){
        worstIndex=-1;
        maxWaste=0;
        for(int j=0;j<m;j++){
            if(process[i]<tempMemory[j]){
                int waste=tempMemory[j]-process[i];
                if(waste>maxWaste){
                    maxWaste=waste;
                    worstIndex=j;
                }
            }
        }
        if(worstIndex!=-1){
            waste[i]=maxWaste;
            tempMemory[worstIndex]-=process[i];
            alloc[i]=worstIndex;
        }
    }
}
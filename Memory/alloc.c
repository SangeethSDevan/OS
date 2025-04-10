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
int main() {
    int n, m, choice;

    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the number of memory blocks: ");
    scanf("%d", &m);

    int process[n], block[m];

    printf("Enter the size of each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &process[i]);
    }

    printf("Enter the size of each memory block:\n");
    for (int i = 0; i < m; i++) {
        printf("Block %d: ", i + 1);
        scanf("%d", &block[i]);
    }

    printf("Choose the allocation strategy:\n");
    printf("1. First Fit\n");
    printf("2. Best Fit\n");
    printf("3. Worst Fit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("\nFirst Fit Allocation:\n");
            firstfit(process, block, n, m);
            break;
        case 2:
            printf("\nBest Fit Allocation:\n");
            bestfit(process, block, n, m);
            break;
        case 3:
            printf("\nWorst Fit Allocation:\n");
            worstfit(process, block, n, m);
            break;
        default:
            printf("Invalid choice!\n");
            return 1;
    }

    return 0;
}
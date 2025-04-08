#include <stdio.h>
#define MAX 10
int absValue(int a,int b){
   return (a>b)?(a-b):(b-a);
}
void cScan(int request[],int n,int head,int disk){
    int totalSeek=0;
    int sorted[MAX+1];
    int current=head;
    int headIndex;

    for(int i=0;i<n;i++){
        sorted[i]=request[i];
    }
    sorted[n]=head;
    for(int i=0;i<=n;i++){
        for(int j=0;j<n;j++){
            if(sorted[j]>sorted[j+1]){
                int temp=sorted[j];
                sorted[j]=sorted[j+1];
                sorted[j]=temp;
            }
        }
    }
    for(int i=0;i<=n;i++){
        if(request[i]==head){
            headIndex=i;
            break;
        }
    }
    printf("%d\t",head);
    for(int i=headIndex+1;i<=n;i++){
        printf("%d\t",sorted[i]);
        totalSeek+=absValue(current,sorted[i]);
        current=sorted[i];
    }

    if(current<disk){
        printf("%d\t",disk-1);
        totalSeek+=absValue(current,disk-1);
        current=disk-1;
    }
    printf("0\t");
    for(int i=0;i<headIndex;i++){
        printf("%d\t",sorted[i]);
        totalSeek+=absValue(current,sorted[i]);
        current=sorted[i];
    }
}
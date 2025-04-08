#include <stdio.h>
#define MAX 10
int absValue(int a,int b){
    return (a>b)?(a-b):(b-a);
}

void sstf(int requests[],int n,int head){
    int totalSeek=0;
    int count=0;
    int visited[MAX]={0};
    int current=head;

    while(count<n){
        int minIndex=-1;
        int minDistance=__INT_MAX__;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                int distance=absValue(current,requests[i]);
                if(distance<minDistance){
                    minDistance=distance;
                    minIndex=i;
                }
            }
        }
        printf("%d\t",requests[minIndex]);
        totalSeek+=absValue(current,requests[minIndex]);
        visited[minIndex]=1;
        count++;
        current=requests[minIndex];
    }
    printf("\n");
}
int main(){
    int requests[] = {12,23,44,11};
    sstf(requests,4,requests[0]);
    
    return 0;
}

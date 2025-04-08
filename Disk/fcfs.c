#include <stdio.h>

int abs(int a,int b){
    return (a>b)?(a-b):(a-b);
}
void fcfs(int request[],int n,int head){
    int totalSeek=0;
    int current=head;

    printf("%d\t",head);
    for(int i=0;i<n;i++){
        printf("%d\t",request[i]);
        totalSeek+=abs(head,request[i]);
        current=request[i];
    }
    printf("Total seek time: %d\n",totalSeek);
    printf("Average seek distance: %d\n",totalSeek/n);
}
void main(){
    int requests[] = {12,23,44,11};
    fcfs(requests,4,requests[0]);
}
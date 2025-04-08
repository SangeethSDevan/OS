#include <stdio.h>
#define MAX 10
int absValue(int a,int b){
    return (a>b)?(a-b):(b-a);
}
void scan(int request[],int n,int head){
    int totalSeek=0;
    int sorted[MAX+1];
    int current=head;
    int direction=1;
    int headIndex=-1;

    for(int i=0;i<n;i++){
        sorted[i]=request[i];
    }
    sorted[n]=head;
    printf("%d\t",head);
    for(int i=0;i<=n;i++){
        for(int j=0;j<n;j++){
            if(sorted[j]>sorted[j+1]){
                int temp=sorted[j];
                sorted[j]=sorted[j+1];
                sorted[j+1]=temp;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(sorted[i]==head){
            headIndex=i;
            break;
        }
    }
    for(int i=headIndex+1;i<=n;i++){
        printf("%d\t",sorted[i]);
        totalSeek+=absValue(current,sorted[i]);
        current=sorted[i];
    }
    for(int i=headIndex-1;i>=0;i--){
        printf("%d\t",sorted[i]);
        totalSeek+=absValue(current,sorted[i]);
        current=sorted[i];
    }

    printf("Total seek time is: %d\n",totalSeek);
    printf("Average seek distance: %d\n",totalSeek/n);
}
int main(){
    int req[]={22,34,25,45,90,12};
    scan(req,6,21);
}
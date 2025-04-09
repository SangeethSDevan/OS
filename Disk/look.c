#include <stdio.h>
#define MAX 10
int absValue(int a,int b){
    return (a>b)?(a-b):(b-a);
}
void look(int request[],int n,int head){
    int totalSeek=0,headPos=-1,current=head;
    int sorted[MAX+1];

    for(int i=0;i<n;i++){
        sorted[i]=request[i];
    }
    sorted[n]=head;
    printf("%d\t",head);
    for(int i=0;i<=n;i++){
        for(int j=0;j<n-i;j++){
            if(sorted[j]>sorted[j+1]){
                int temp=sorted[j];
                sorted[j]=sorted[j+1];
                sorted[j+1]=temp;
            }
        }
    }

    for(int i=0;i<=n;i++){
        if(sorted[i]==head){
            headPos=i;
            break;
        }
    }
    for(int i=headPos+1;i<=n;i++){
        printf("%d\t",sorted[i]);
        totalSeek+=absValue(current,sorted[i]);
        current=sorted[i];
    }
    for(int i=headPos-1;i>=0;i--){
        printf("%d\t",sorted[i]);
        totalSeek+=absValue(current,sorted[i]);
        current=sorted[i];
    }
    printf("\n");
    printf("Total seek time: %d\n",totalSeek);
}
int main(){
    int req[]={10, 20, 30, 60, 70, 80};
    look(req,6,50);
}
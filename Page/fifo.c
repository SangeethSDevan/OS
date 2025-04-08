#include <stdio.h>
void printPages(int frames[],int f){
    for(int i=0;i<f;i++){
        if(frames[i]==-1){
            printf("-");
        }else{
            printf("%d",frames[i]);
        }
    }
    printf("\n");
}
void fifo(int pages[],int n,int f){
    int frames[f];
    int index=0,pageFaults=0;
    for(int i=0;i<f;i++){
        frames[i]=-1;
    }
    for(int i=0;i<n;i++){
        int hit=0;
        for(int j=0;j<f;j++){
            if(frames[j]==pages[i]){
                hit=1;
                break;
            }
        }
        if(!hit){
            pageFaults++;
            frames[index]=pages[i];
            index=(index+1)%f;
        }
        printPages(frames,f);
    }
    printf("Page faults: %d\n",pageFaults);
}
int main(){
    int pages[]={2,3,4,1,2,3,5,3};
    fifo(pages,8,3);
}
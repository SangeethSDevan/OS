#include <stdio.h>
void printFrames(int frames[],int f){
    for(int i=0;i<f;i++){
        if(frames[i]==-1){
            printf("-");
        }else{
            printf("%d",frames[i]);
        }
    }
    printf("\n");
}
int findLFU(int count[],int times[],int f){
    int min=count[0],pos=0;
    for(int i=0;i<f;i++){
        if(count[i]<min){
            min=count[i];
            pos=i;
        }else if(count[i]==min){
            if(times[i]<times[pos]){
                pos=i;
            }
        }
    }
    return pos;
}
void lfu(int pages[],int n,int f){
    int frames[f],count[f],times[f],time=0;
    int pageFaults=0;

    for(int i=0;i<f;i++){
        frames[i]=-1;
        count[i]=0;
        times[i]=0;
    }
    for(int i=0;i<n;i++){
        int hit=0;
        for(int j=0;j<f;j++){
            if(frames[j]==pages[i]){
                hit=1;
                count[j]++;
                times[j]++;
                break;
            }
        }
        if(!hit){
            int pos=-1;
            for(int i=0;i<f;i++){
                if(frames[i]==-1){
                    pos=i;
                    break;
                }
            }
            if(pos==-1){
                pos=findLFU(count,times,f);
            }
            frames[pos]=pages[i];
            count[pos]=1;
            times[pos]=time++;
            pageFaults++;
        }
        printFrames(frames,f);
    }
    printf("Page faults: %d\n",pageFaults);
}
int main(){
    int pages[]={2,3,4,1,2,3,5,3};
    lfu(pages,8,3);
}
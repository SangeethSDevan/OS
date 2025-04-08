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
int findLRU(int time[],int f){
    int min=time[0],pos=0;
    for(int i=0;i<f;i++){
        if(time[i]<min){
            min=time[i];
            pos=i;       
        }
    }
    return pos;
}
void lru(int pages[],int n,int f){
    int frames[f],time[f];
    int counter=0,pageFaults=0;
    for(int i=0;i<f;i++) frames[i]=-1;

    for(int i=0;i<n;i++){
        int hit=0;
        for(int j=0;j<f;j++){
            if(frames[j]==pages[i]){
                counter++;
                time[j]=counter;
                hit=1;
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
                pos=findLRU(time,f);
            }
            frames[pos]=pages[i];
            counter++;
            time[pos]=counter;        
            pageFaults++;
        }
        printFrames(frames,f);
    }
}
int main(){
    int pages[]={2,3,4,1,2,3,5,3};
    lru(pages,8,3);
}
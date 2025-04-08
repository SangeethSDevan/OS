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
    
}
int main(){
    int pages[]={2,3,4,1,2,3,5,3};
    fifo(pages,8,3);
}
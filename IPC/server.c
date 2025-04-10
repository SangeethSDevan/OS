#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <string.h>

int main(){
    void * sharedMemory;
    char buffer[100];
    int shmid;

    shmid=shmget((key_t)3030,27,0666 |IPC_CREAT);
    printf("Key of shared memory: %d\n",shmid);
    sharedMemory=shmat(shmid,NULL,0);
    printf("Process attached at %p\n",sharedMemory);
    read(0,buffer,100);
    strcpy(sharedMemory,buffer);
    printf("Data written is: %s\n",(char *)sharedMemory);
}   
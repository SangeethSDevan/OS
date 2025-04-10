#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <string.h>

int main(){
    void * sharedMemory;
    char buffer[100];
    int shmid;

    shmid=shmget((key_t)3030,27,0666|IPC_CREAT);
    printf("Key of shared memory: %d\n",shmid);

    sharedMemory=shmat(shmid,NULL,0);
    printf("Process attached at position %p\n",sharedMemory);
    printf("Data Read: %s\n",(char *)sharedMemory);
}
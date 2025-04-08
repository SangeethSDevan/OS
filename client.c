#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <string.h>

int main() {
    void *shared_memory; // a pointer that is not associated with any data types.
    // It points to some data location in the storage
    char buff[100];
    int shmid;
    
    shmid = shmget((key_t)3000, 27, 0666 | IPC_CREAT);
    printf("key of shared memory is %d\n", shmid);
    
    shared_memory = shmat(shmid, NULL, 0); // NULL value means that the system will
    // automatically choose a suitable address
    
    printf("Process attached at %p\n", shared_memory); // %p an address (or pointer)
    printf("Enter some data to write to shared memory\n");

    read(0, buff, 100); // get some input from user
    strcpy(shared_memory, buff); // data written to shared memory
    printf("You wrote: %s\n", (char*)shared_memory);
}
